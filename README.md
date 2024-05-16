# ADVANCE C
---

<details><summary>LESSON 1: Compiler - Macro</summary>
</p>

</p>

</details>

<details><summary>LESSION 2: STDARG - ASSERT</summary>
</p>
Thư viện Stdarg cung cấp các phương thức làm việc với các input parameter không xác định. Ví dụ điển hình là *scanf*,*printf*
Các tham số:
   + va_list:là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
   + va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
   + va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ .
   + va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

Thư viện Assert
   + Cung cấp macro assert. 
   + Macro này được sử dụng để kiểm tra một điều kiện. 
   + Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
   + Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
   + Dùng trong debug, dùng #define NDEBUG để tắt debug
</p>

</details>

<details><summary>LESSON 3: POINTER</summary>
</p>

### Introduction to Pointer in C
Pointer is the variable that store address of another object.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/68cbf054-eb00-4e7b-a7d7-9d988eb7d704)

Ví dụ: một con trỏ P lưu địa chỉ của biến a. Khi đó p = &a 
*Khai báo con trỏ*: datatype *ptr;. Khi gọi p tức là con trỏ , nó lưu địa chỉ của biến a nên giá trị của con trỏ là địa chỉ của biến a(p = &a), còn muốn lấy giá trị của biến a thì dùng *ptr.

### Working with Pointer
1.
Ta có thể thay đổi giá trị của một biến thông qua con trỏ. Bằng cách trỏ tới địa chỉ của biến đó và thay đổi giá trị tay địa chỉ của biến.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/3616c1d7-6ef9-4f67-a509-b0d0c143cca3)


Ở ví dụ này tôi đã trỏ tới địa chỉ của biến a và change value of a variable. The new value of a variable is 20. Tôi chỉ thay đổi giá trị tại vùng địa chỉ mà con trỏ trỏ tới chứ không thay đổi địa chỉ nên output của chương trình địa chỉ của a vẫn không thay đổi 
=> Out put của chương trình:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/c07632fa-ddc2-4bd7-91b4-eb616b3a5c27)

2. Pointer Arithmetic
Giả sử địa chỉ của biến a là 2002 thì p+1 = ? Có phải là 2003 không?

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/10b8bfa7-6e79-4151-94f3-56463dec17fa)

Câu trả lời là không nhé. Bởi vì p là một con trỏ kiểu interger thì khi tăng nó lên 1 tức là đi tới địa chỉ của integer tiếp theo. Bởi vì size của integer là 4 byte nên go to the next integer, nghĩa là we need to skip four. Tức là p + 1 = 2002 + 4 = 2006.

3. Void Pointer 
Void Pointer: là con trỏ trỏ tới địa chỉ bất kì mà không cần biết kiểu dữ liệu của nó. Chúng ta chỉ được lưu địa chỉ của đối tượng khác vào con trỏ void chứ không xem được giá trị tại địa chỉ mà nó trỏ tơi

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/ee7a2725-7895-484d-b8dc-36cf4fbb52a6)

=> Dòng *p0, p0+1 sẽ lỗi, tại vì con trỏ void nó không có kiểu dữ liệu nên ta không thể lấy giá trị tại địa chỉ như này, còn p0+1 thì bản chất nó là trỏ tới địa chỉ tiếp theo, tức là cộng thêm kích thước của 1 con trỏ mà này kểu void->nó không có kiểu dữ liệu nên chúng ta không thể tính toán được địa chỉ. 
***=>Không thể lấy giá trị or địa chỉ tiếp theo khi dùng con trỏ void***
4. Pointer to Pointer
Là con trỏ lưu địa chỉ của con trỏ khác

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/cc6195d8-c200-4905-b557-2e340dcbc985)

Trong ví dụ này: q chính là con trỏ cấp 2.

*Cách nhớ:* 

            + int : khai báo biển có kiểu dử liệu là integer

            + int* : khai báo con trỏ lưu địa chỉ của biến
            
            + int**: khai báo con trỏ để lưu địa chỉ của con trỏ.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/0ffabc9e-2796-4dbb-9d34-1247638bad54)

=> Muốn thay đổi giá trị của a mình chỉ cần gán: ***r = 10; output a = 10;
                                                 **q = *q + 2; output a = 12;

5. Pointers as function arguments - Call by Reference



</p>

</details>

<details><summary>LESSON 4: MEMORY LAYOUT</summary>
</p>
   
 **Mục đích bài học:** Cách tổ chức và phân bổ đóng vai trò quan trọng trong việc thực thi một chương trình. Hiểu được nó thì ta sẽ có nền tảng trong việc lập trình.

 In C programming language, **the memory layout** consists of the following sections:
> - Text segment.
> - Initialized data segment.
> - Uninitalized data segment.
> - Heap.
> - Stack.

 Diagram
 
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/afd40e65-9551-4a53-a6f3-58ae27f644fa)

#### - **Text Segment**: 
- Sau khi **compile** chương trình thì chúng ta sẽ có những file nhị phân (những file mà được dùng để execute chương trình của chúng ta khi đổ vào RAM), những file nhị phân (.o) này chứa những cái **instructions**. Và những cái instructions này sẽ stored ở Text Segment of the memory.  
- Text Segment chỉ được read không được modify.
#### - **Initialized Data**:
- Initialized Data( data segment): contain values of all static, global, external and constant những cái được initialized trong time thực thi chương trình(# 0).
- Được phép đọc - ghi (vì các value của variables sẽ thay đổi trong khi thực thi chương trình nó không mãi là một constant được nên phải có thể được modify).
- Ví dụ: dưới đây mình khai báo 2 biến , biến **c** được khái báo có giá trị nên nó sẽ nằm trong vùng **data segment** của memory, còn biến **a** sẽ không nằm trong vùng data mà sẽ nằm ở vùng khác.

   ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/9df292be-e1d7-4245-aa67-70c6256c496b)

#### - **Uninitialized Data**:
- Uninitialized Data(BSS): chứa những biến chưa khởi tạo giá trị, và cũng có thể chứa nhưng biến static or global mà được khởi tạo với giá trị là 0.
- Cho phép đọc và ghi.
- Trở lại ví dụ phía trên thì **a** variable sẽ stored in BSS.

> *Một kiểu dữ liệu thì sẽ không nằm trong vùng nào hết, khi nó khai báo biến thì biến đó mới được lưu trong vùng data (initialized or uninitialized) tùy thuộc vào giá trị mà biến đó được khai báo.*
#### - **Heap**:
- Dùng cho bộ nhớ để cấp phát động( trong thời gian chạy chương trình).
- Có thể điều khiển quá trình cấp phát hoặc giải phóng bộ nhớ bằng các câu lệnh như **malloc, calloc, relloc. free, delete,**...
- Khi dùng xong thì phải delete nếu không sẽ bị leak memory.
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/659d19b0-b7c7-470c-8cc8-ceeaf96db913)
- Malloc & Calloc: 
>- Malloc: void * malloc(size_t size);
>- Mục đích: cấp phát một vùng nhớ có kích thước là **size**.
>- Tham số truyền vào: **1**
>- Kết quả trả về: là một con trỏ tới vùng nhớ được cấp phát nếu success, NULL nếu fail.
>- Giá trị khởi tạo: là giá trị rác.

>- Calloc: void * calloc(size_t num, size_t size);
>- Mục đích: cấp phát một vùng nhớ có chứa **num** phần tử, mỗi phần tử có kích thước là **size**.
>- Tham số truyền vào: **2**
>- Kết quả trả về: là một con trỏ tới vùng nhớ được cấp phát nếu fail, NULL nếu success.
>- Giá trị khởi tạo: là 0.

Hiệu suất của **malloc** sẽ nhanh hơn **calloc** vì ngoài việc cấp phát vùng nhớ giống **malloc** thì **calloc** còn phải gán cho các phần tử của vùng nhớ vừa cấp phát giá trị là 0.
Muốn sử dụng calloc hay malloc thì tùy vào người dùng nếu không care tới value của vùng nhớ cấp phát thì use **malloc**, còn nếu muốn all có value bằng 0 thì mình dùng **calloc**.
#### - **Stack**:
-  Khác với Heap thì Stack là một vùng nhớ được cấp phát tự động 
- Mỗi khi các function được gọi thì nó sẽ được push vào vùng stack.

</p>

</details>
<details><summary>LESSION 5: EXTERN - STATIC - VOLATILE - REGISTER</summary>
</p>

### EXTERN ###
- Dùng để tham chiếu một biến, hàm có cùng name đã được định nghĩa ở nơi khác.
- Khai báo thôi chứ không định nghĩa, biến được kêu ra phải là biến toàn cục của file khác.
### STATIC ###
#### Static với biến cục bộ #### 
- Một biến được khai báo(định nghĩa hay không định nghĩa) thì nó sẽ bị thu hồi vùng nhớ sau khi ra hỏi hàm. Muốn giữ giá trị của nó không bị mất khi ra khỏi hàm thì dùng từ khóa **Static**.

Ví dụ nếu không dùng biến static:
 
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/fd25bd89-17b3-44ad-a9d5-521031dc7fab)            ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/a567a788-8c2a-497a-b739-b6c818cb3a3c)

               
Ví dụ nếu dùng biến static:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/8ba48217-1993-4adc-b449-0c11dfe0608d)            ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/103c348a-60ff-48bd-a61a-4185ca616ded)

#### Static với biến toàn cục và hàm: ####
- Dùng được trong chương trình không cho bên ngoài dùng kể cả **EXTERN.**
### VOLATILE ###
### REGISTER ###

</p>

</details>

<details><summary>LESSON 6: GOTO - SETJMP</summary>
</p>
*Goto* là một từ khóa trong ngôn ngữ lập trình C cho phép người dùng nhảy đến một label đã được đặt trước đó trong cùng một. Không được khuyến khích dùng vì nó làm cho chương trình trở nên khó đọc và bảo trì. 
>- Ví dụ về từ khóa *go to*

                            #include <stdio.h>
                            void delay(double second)
                            {
                                double start = 0;
                                while (start < second * 6000000)
                                {
                                    start++;
                                }
                            }
                            // Khai báo các trạng thái đèn giao thông
                            typedef enum //1 thời điểm chỉ có 1 đèn để 
                            {
                                RED,
                                YELLOW,
                                GREEN
                            } TrafficLightState;
                            int main() {
                                // Ban đầu, đèn giao thông ở trạng thái đỏ
                                TrafficLightState state = RED;
                            
                                // Vòng lặp vô hạn để mô phỏng đèn giao thông
                                while (1) {
                                    switch (state) {
                                        case RED:
                                            printf("RED Light\n");
                                            delay(50);  // Giữ trạng thái đèn đỏ trong x giây
                                            
                                            // Chuyển đến trạng thái đèn xanh
                                            state = GREEN;
                                            goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                        case YELLOW:
                                            printf("YELLOW Light\n");
                                            delay(20);  // Giữ trạng thái đèn vàng trong y giây
                                            
                                            // Chuyển đến trạng thái đèn đỏ
                                            state = RED;
                                            goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                        case GREEN:
                                            printf("GREEN Light\n");
                                            delay(100);  // Giữ trạng thái đèn xanh trong z giây
                                            
                                            // Chuyển đến trạng thái đèn vàng
                                            state = YELLOW;
                                            goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                    }
                                    // Nhãn để nhảy qua sleep() khi chuyển trạng thái
                                    skip_sleep:;
                                }
                                return 0;
                            }

 >- Trong ví dụ trên trạng thái đèn đỏ đầu tiên, khi chờ khoảng 50s thì trạng thái đèn xanh, nó sẽ thoát ra khỏi switch và bắt đầu switch case khác vì nó đã dùng label skip_Spleep (cái này được đặt ngoài hàm nên nôn na sẽ thoát khỏi hàm, lần lượt chuyển sang đèn khác thứ tự là **ĐỎ - XANH - VÀNG**
*Setjmp.h* là một thư viện trong ngôn ngữ lập trình C cung cấp 2 hàm là *setjmp* và *longjmp* dùng để xử lí ngoại lệ trong( nó không tiêu biểu để xử lí ngoại lệ trong ngôn ngữ này).
>- Ví dụ về *Setjmp.h*

                       #include <stdio.h>
                       #include <setjmp.h>
                       
                       jmp_buf buf;
                       int exception_code;
                       
                       #define TRY if ((exception_code = setjmp(buf)) == 0) 
                       #define CATCH(x) else if (exception_code == (x)) 
                       #define THROW(x) longjmp(buf, (x))
                       
                       
                       double divide(int a, int b) {
                           if (b == 0) {
                               THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
                           }
                           return (double)a / b;
                       }
                       
                       int main() {
                           int a = 10;
                           int b = 0;
                           double result = 0.0;
                       
                           TRY {
                               result = divide(a, b);
                               printf("Result: %f\n", result);
                           } CATCH(1) {
                               printf("Error: Divide by 0!\n");
                           }
                       
                       
                           // Các xử lý khác của chương trình
                           return 0;
                       }
</p>

</details>

<details><summary>LESSON 7: BITMASK</summary>
</p>
   
Được sử dụng để tối ưu hóa bộ nhớ.

- NOT biswise: Khi thực hiện phép toán này thì kết quả của nó là đão của nó. Ví dụ: 1 not bitwise được kết quả là 0
- AND biswise: Kết quả là 1 nếu 2 bit đều là 1, còn lại là 0.
  * Có 1 phép toán hay. Ví dụ nếu ta muốn coi 1 số là chẵn lẽ thì mình có thể dùng %2 nhưng ngoài ra mình cũng có thể sử dụng bitwise AND(&). Mình chỉ cần & số đó với 1(&1).
  * Nếu kết quả là 1 thì số đó là số lẻ, còn kết quả là 0 thì số đó là số chẵn
  * Giải thích: tại vì số lẻ là số có bit bên trái ngoài cùng là 1, còn số chẵn thì là số 0. Khi &1 thì tất cả 7 bit trong đều về 0, còn trạng thái của bit cuối &1 thôi. Nên nếu 1&1 sẽ ra 1=>số chẵn, ngược lại số lẻ.
- OR biswise: 0 OR 0 là 0, còn lại là 1.
- XOR bitwise: giống nhau thì bằng 0, khác nhau = 1.
- Sift Left và Shif Right bitwise: << (dịch trái) , >> (dịch phải).
  * Thường ta sẽ bù bit 0 nhưng khi dịch phải có 1 lưu ý đó là: phải chú ý đến bit cao nhất(bit dấu).
  * Bit dấu: nếu bit max là 1 thì đó là số âm nên khi dịch phải mình bù vào số 1.
  * Còn nếu là số dương (bit dấu = 0) thì khi dịch phải truyền vào số 0.

## **LESSION 8: Struct - Union** 
## **LESSION 9: JSON**
JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/d07554e4-417f-46d6-a95b-e2ec7cc5d5fd)

Có 6 loại định dạng trong JSON: *NULL, NUMBER, ARRAY, STRING, BOOLEAN, OBJECT.*
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/aafc3aad-85d5-49ec-97c3-a840059f4e96)

**một object có thể co nhiều key-value**
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1963a8cf-ce0e-485d-92b3-487d9b8ef317)

</p>

</details>

<details><summary>LESSON 10: LINKED LIST</summary>
</p>

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/0153edae-9d15-4b48-be4c-f4ba1b1950a4)

Mình có một mảng này, muốn xóa 1 phần tử bất kì trong chuỗi ta làm lần lượt các bước: cho giá trị tại vị trí đó là *null* xong nhích giá trị hiện tại lên, giá trị phần tử cuối cùng mình reallocate để chuỗi còn (n-1) phần tử. **=> Đặt ra vấn đề:Nếu như một mảng có 10000 phần tử chả nhẻ xóa ở vị trí bất kì mình dịch chuyển 9999 vòng lặp như thế sao?**
Hoặc ví dụ nếu mình muốn thêm một phần tử thì các bước : cấp phát thêm ở vị trí cuối mảng (null), sau đó xê dịch lần lượt ra.

*=> Việc xóa hay chèn 1 phần tử rất là mất thời gian* => người ta đưa ra **linked list(mảng nhân tạo)** 

Linked List là một cấu trúc dữ liệu trong lập trình máy tính dùng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các nút (node), mỗi nút chứa một giá trị dữ liệu hoặc một con trỏ(pointer) tới nút tiếp theo trong chuỗi. Note cuối thì con trỏ NULL.
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/4eb21968-3ec1-47fb-add8-267b0711b462)

Muốn thêm một node vào cuối một mảng thì mình tạo ra một note trước, giá trị của con trỏ là null, sau đó mình lưu địa chỉ của nó vào pointer của note trước nó.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1ef71755-233e-46dd-bc8a-60fbfc47ba5a)

*Ví dụ:* thêm node vào vị trí thứ 2 của mảng: ta chỉ cần thay đổi pointer của nút cần thêm vào là dịa chỉ của phần từ tiếp theo , và thay đổi pointer của nút trước đó thành địa chỉ của nút mình muốn thêm vào

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/ecddb42e-c932-490e-b0a5-d92d97b9e8b5)

Tương tự ví dụ:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/46abea42-aac1-4728-8614-21e1238296eb)

=>Muốn xóa một phần tử tại vị trí bất kì ta chỉ cần gì note của phần tử đó vào node của phần tử đứng trước đó(tương đương với ghi địa chỉ của phần tử tiếp theo vào vị trí của phần tử đứng trước đó vì note của phần tử đó lưu địa chỉ của phần tử đứng sau)

</p>

</details>

<details><summary>TEST KIẾN THỨC</summary>
</p>
   
## **Câu 1: Sự khác nhau giữa MACRO và FUNCTION**

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1ad5ec14-7d7e-4547-9a31-5f275a982c1a)

## **Câu 2: Các phân vùng nhớ trên RAM và đặc tính của từng phân vùng**

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/c6bc84e5-6159-4a0b-b006-24a33a6af604)

Có 5 phân vùng nhớ trêm RAM (MEMORY LAYOUT):
+ Text: - ở phân vùng này chứa các mã thực thi.
        - chứa các biến con trỏ kiểu char hoặc các const.
        - Quyền truy cập: các biến mà lưu ở vùng này chỉ phép được đọc chứ không được ghi.
  
+ Ininitalized data(Data): - vùng này chứa các biến toàn cục or static đã được khai báo với giá trị khác 0
                           - Quyền truy cập: có thể đọc và ghi.
                           - Các biến sẽ được thu hồi khi chương trình kết thúc.

+ Uninitalized data(BSS):  - vùng này chứa các biến toàn cục or static khai báo với giá trị bằng 0 hoặc chưa gán giá trị.
                           - Quyền truy cập: có thể được đọc và ghi.
  
+ Heap: - Sử dụng để cấp phát bộ nhớ trong quá trình thực thi chương trình.
        - Cho phép chương trình tạo ra và giải phòng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
        - Các hàm: malloc(), calloc() dùng để cấp phát động, hàm realloc(), free() để giải phóng bộ nhớ.
  
+ Stack: - chứa các biến cục bộ, các tham số truyền vào hàm.
         - Quyền truy cập: có thể được đọc và ghi.
         - Sau khi ra khỏi hàm sẽ tự động thu hồi vùng nhớ.

## **Câu 3: Biến STATIC toàn cục và cục bộ**
**Static toàn cục(GLOBAL)**: bình thường biến toàn cục có thể được dùng ở file khác dùng các pp như include,extern. Nhưng nếu chỉ muốn biến toàn cục đó dùng trong file hiện tại thôi thì mình sẽ dùng nó chung với từ khóa STATIC. 

**Static cục bộ(LOCAL)**: bình thường một biến cục bộ(nằm trong stack) thì nó sẽ bị thu hồi vùng nhớ khi ra khỏi hàm. Biến static cục bộ nghĩa là khi được khai báo thì biến nó tồn tại trong suốt thời gian thực thi chương trình nhưng chỉ được thực thi trong hàm chứa nó thôi.

## **Câu 4: So sánh Struc và Union**
Cả 2 đều là kiểu dữ liệu do người dùng tự định nghĩa.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/19805161-8c72-4e19-836c-5e420ae13620)

## **Câu 5: Con trỏ là gì và kích thước của con trỏ, con trỏ hàm, con trỏ void, con trỏ null, pointer to pointer**

- Con trỏ: là biến lưu giá trị, mà giá trị đó là địa chỉ của đối tượng khác (***chú ý: không được kêu là con trỏ là biến lưu địa chỉ của biến khác tại vì hàm,mảng cũng có địa chỉ***).
- Kích thước của con trỏ phụ thuộc vào kiến trúc của vi xử lí (vxl 8 bit thì kích thước con trỏ 1 byte, 32bit là 4 byte, 64bit là 8 byte).
- Con trỏ hàm: là con trỏ lưu địa chỉ của một hàm.
- Con trỏ null: là con trỏ mà nó không trỏ tới một đối tượng hay vùng nhớ nào.
- Con trỏ voil: là con trỏ trỏ tới vùng nhớ không có kiểu dữ liệu.
- Pointer to Pointer: là con trỏ lưu địa chỉ của con trỏ khác.

## **Câu 6: Biến REGISTER VÀ VOLATILE**

**REGISTER**:Trong khi các biến khai báo trong chương trình thì đặt ở bộ nhớ ngoài (RAM chẳng hạn …). Do đó với khai báo biến thông thường, để thực hiện một phép tính thì cần có 3 bước.
 + Nạp giá trị từ vùng nhớ chứa biến vào 
 + Yêu cầu ALU xử lý register vừa được nạp giá trị.
 + Đưa kết quả vừa xử lý của ALU ra ngoài vùng nhớ chứa biến.
Khi thêm từ khóa register để khai báo biến, thì tức là ta đã yêu cầu trình biên dịch ưu tiên đặc biệt dành luôn vùng register để chứa biến đó. Và hiển nhiên khi thực hiện tính toán trên biến đó thì giảm được bước 1 và 3, giảm bớt thủ tục vậy nên hiệu năng tăng lên.
  
**VOLATILE**: Một biến cần được khai báo dưới dạng biến volatile khi nào? Khi mà giá trị của nó có thể thay đổi một cách không báo trước. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler. 3 ví dụ trong thực tế nên dùng biến volatile
 + Memory-mapped peripheral registers (thanh ghi ngoại vi có ánh xạ đến ô nhớ)
 + Biến toàn cục được truy xuất từ các tiến trình con xử lý ngắt (interrupt service routine)
 + Biến toàn cục được truy xuất từ nhiều tác vụ trong một ứng dụng đa luồng.

## Câu 7: Khác nhau giữa struct và class trong c++
1. Member của Class mặc định là private, còn của Structe mặc định là public
2. Cái instance sử dụng class gọi là object, đối với structure gọi là biến.
3. Class dùng để đóng gói dữ liệu hoặc kế thừa còn struct dùng để group các kiểu dữ liệu lại
4. Trong class có thể có giá trị NULL,còn trong struct không thể có giá trị null.
</p>

</details>


<details><summary>MỘT SỐ THUẬT TOÁN HAY</summary>
</p>
Số âm & Số dương:

   ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/fca931ea-0af4-4271-a004-401f1c6aff48)


## Câu 1: Tìm giá trị Max của 2 số mà không dùng if else, switch case, toán tử 3 ngôi, toán tử so sánh.
printf("%d" , (a+b+abs(a-b))/2);

## Câu 2: Một số thuật toán sắp xếp
Sắp xết chọn(Selection Sort)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/febde365-f6f9-4446-8daa-37a6909708c9)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/a96c19dd-e3b3-4335-bc47-0492be6886a1)


</p>

</details>

# ADVANCE C++

<details><summary>LESSION: Linh tinh</summary>
</p>
   
**1. Câu lệnh để nhận dữ liệu trên 1 dòng:** ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/a68fc70c-d085-4c3b-8868-9a201455572d)



</p>
</details>
<details><summary>LESSION 13: CLASS</summary>
</p>

Trong C++, từ khóa 'class' dùng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/d8327aae-3ff8-4bb8-bc0d-848d89e9d27f)

Trong C++ thì các biến(variable) gọi là property, các hàm(function) gọi là method

- Declaring Object

  ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/f5ed4cdc-a743-435c-89b5-375f1e8112c3)

- Contructor trong C++ là một method sẽ được tự động gọi khi object được tạo ra. Constructor sẽ có tên trùng với tên của class.
- Deconstructor trong C++ là một method sẽ được tự động gọi khi object được giải phóng. Deconstructor có tên trùng với tên của class , thêm ~ ở trước tên.

***Static Keyword***:
- Nếu như một property được khai báo với từ khóa static thì các object trong class sẽ dùng chung địa chỉ vơi property này.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/331ff9b4-7d0b-4ca8-b4d6-856dc11c5f8b)

Output của chương trình trên:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/470af029-a2cd-46a2-9246-a42ab3d8a4eb)

Các object trong class dùng biến var thì sẽ có chung địa chỉ.

- Nếu như một method được khai báo với từ khóa static:
 >- Method này độc lập với bất kỳ đối tượng nào của lớp.
 >- Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
 >- Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
 >- Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
 >- Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.

## Binary Search ##

[</p>

</details>

<details><summary>LESSION 14: OOP</summary>
</p>
   
#### 1. Passing Object as Function Argument

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/c998396a-c9e7-412e-80ab-9e71fe0b6691)

*Có 3 loại Constructor: default constructor, copy constructor, *

#### 2. How to Constructor Overloading
The process of declaring multiple constructors with same  name but different parameters is known as xonstructor .
=> Destructor ko overloading tại vì trong 1 class chỉ có 1 destructor.
#### 3. Default copy constructor
Dùng để khai báo một đối tượng với một đối tượng khác cùng loại 
#### 4. Static Data Member & Static member function
+ Static Data Memmber: Chỉ được sử dụng trong class nhưng thời gian tồn tại của nó thì là suốt chương trình, kể cả khi không có đối tượng được khởi tạo thì nó cũng sẻ tồn tại
+ Static member function: chỉ truy cập đươc bởi các đối tượng trong class.

#### 5. Friend Function & Class Function
- Friend Function của một class được định nghĩa bên ngoài class nhưng mà nó thể truy cập được tất cả thuộc tính bên trong class kể cả private and protected.
- Frined không phải là member function của class. Vs dụ:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/fd147721-0b80-48b3-824f-30947a8fcd89)

- Friend class cũng được khai báo như là friend của một class

### 6. OOP1. Inheritance

- Inheritance(tính kế thừa): là khả năng sử dụng các thuộc tính của lớp khác
- Class cho kế thừa gọi là Parent or Base or Super Class, còn những class đi sử dụng properties của class khác gọi là Child, Derived or Sub Class.
- Tất cả các member của class có thể được kế thứa (except Private).

*Type of Inheritance*
- Single Inheritance
- Multiple Inheritance
- Hierarchical Inheritance
- Multilevel Inheritance
- Hybrid Inherutance

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/b823fda0-1f0c-4f33-b38f-65133527acee)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/df623960-b78f-4cc3-9f62-88aba57531de)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1b4bb8c3-223f-4e5d-b69b-ab3b1783d84c)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/0c7e8277-6563-4dcf-9512-a4c3d66b3a59)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/e388052d-77b8-46a1-afb7-80bac39b0dfa)

### 7. OOP2. Encapsulation in C++
Nó được định nghĩa như là đóng gói dữ liệu và thông tin thành một đơn vị duy nhất,chúng được định nghĩa là định nghĩa là liên kết dữ liẹu và các chứng năng với  nhau.

***Ví dụ***: Một công ty sẽ có nhũng team tài chính, sale, account,..... Mỗi bộ phận này sẽ xử lí những dữ liệu liên quan tới bộ phận của họ và họ phải lưu cái records lại. Vì một số lí do nào đó có thể team sales cần hồ sơ của team tài chính. Thì team sales không thể trực tiếp truy cập vào dữ liệu của team tài chính được mà phải gửi yêu cầu để nhân viên bên team sales đóng gỏi dữ liệu và gửi yêu cầu cho team tài chính

*Two important property of Encapsulation*
+ Data protection: bảo vệ dữ bằng cách giữ cho dữ liệu private, cái việc truy cập và chỉnh sửa dữ liệu nó sẽ bị hạn chế hơn so với những hàm public.
+ Information Hiding: ẩn đi những chi tiết triển khai nội bộ trong hàm chỉ có những cái public mới có thể truy cập.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/61a7877f-cb14-44e0-be19-c54cec2b3935)

Encapsulation nó cũng dẫn đến tính trừu tượng của dữ liệu,nó sẽ ẩn đi những dữ liệu.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/ecaeb1fa-63d7-47f4-bfa1-a34485fd675e)

Trong ví dụ bên dưới: age là private. Biến này nó được truy cập thông qua hàm getAge() và setAge() , 2 hàm được dùng bên trong class. Trong ví dụ này biến x, 2 hàm kia liên kết với nhau không có gì khác ngoài sự Encapsulation.

### 8. OOP 3: Abstraction
Abstaction: có nghĩa là sẽ trưng bày những thông tin cần thiết và ẩn đi chi tiết. 
Ví dụ: chúng ta chỉ biết là khi nhấn ga thì xe chạy nhanh còn bóp thắng thì xe dừng lại. Nhưng chúng ta không hề biết khi nhấn ga thì tốc độ nó tăng như nào hoặc cơ cấu cơ khi để giảm phanh như nào. Đây chính là trừu tượng. 
Có 2 loại trừu tượng:
+ Data Abstraction: Chỉ hiển thị những thoong tin yêu cầu về dữ liệu và ẩn đi những thông tin cần thiết.
+ Control Construction: Hiển thị những thông tin yêu cầu về việc thực hiện cụ thể(cái ẩn đi của cái kia) và ẩn đi những thông tin không cần thiết.

***Khác nhua giữa Encapsulation và Abstaction***:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/3a075966-76d0-4747-a6e5-107f1f054a43)

### 9. OOP: Polymorphism
Polymorphism là một trong những tính năng quan trọng của C++. Polymorphism có nghĩa là nó có nhiều forms(hình thức). Là một đối tượng nhưng thực hiện những hành vi khác nhau trong những trường hợp khác nhau. 
Ví dụ: cùng 1 người nhưng tại một thời điểm họ có thể là con của một ai đó, học sinh của trường nào đó hay ứng cử viên tham gia cuộc phỏng vấn nào đó.
Có 2 loại Polymorphism:
+ Compiler-time
+ Runtime

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/3b24cd0a-a5ef-469f-85bd-9a55dbbab310)

1. Compyler-time

***Sực khác nhau giữa Inheritance và Polymorphism***:
1. Inheritance là một class mới được tạo ra kế thừa những tính năng của class hiện tại, trong khi đó polymorphism là cái mà nó có thể được định nghĩa dưới nhiều hình thức.
2. Inheritance thường ap dụng cho nhiều lớp, còn Polymorphism thường áp dụng cho hàm hoặc method.
3. Inhertitance hổ trợ việc tái sử dụng và giảm thiểu chiều dài của code trong hướng đối tượng, tình đa hình cho phép đối tượng quyết định cái form nào của function được thực hiện.
4. Inheritance có thể là single, hybrid, multiple, hierarchical, multilevel inheritance. Còn polymorphism có thể là compiler-time polymorphism cũng như run time polymorphism 
</p>

</details>


<details><summary>LESSION15: LAMDA FUNCTION</summary>
</p>
Là một cơ chế để thiết lập những hàm vô danh(không có tên). Khi chúng được thiết lập chúng ta có thể gọi nó, hoặc làm bất cứ cái gì một cách trực tiếp với nó.
   
*Lamda Function signature:* [capture] (parameters) -> return type {};

**Parameter**
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/d29ded15-1435-4d5c-af76-00fbea7e7761)

Output: 17.8, có thể gọi landa function bằng cách gán cho nó một cái name.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/58963200-221e-4550-a6a4-4b76f49830f0)

có thể truyền tham số trực tiếp vào lamda.

**Capture list**
- Capture list trong lamda funtion như copy giá trị khai báo bên ngoài vào vậy. Nghĩa là  trong [] chúng ta chỉ có thể pass vào nó các trường hợp sau, ***nó không được khai báo trực tiếp bên trong []***
   - [] : không giữ biến nào.
   - [val]: giá trị cuẩ biến.
   - [&val]: tham chiếu của biến.
   - [=]: tất cả giá trị của biến.
   - [&]: tất cả tham chiếu của biến.
 </p>
</details>

<details><summary>LESSION16: FUNCTION TEMPLATE</summary>
</p>
Trong C++, function templates là một tính năng mạnh mẽ giúp việc các function và class chung sử dụng cho nhiều kiểu dữ liệu mà không cần phải triển khai nhiều phiên bản của function hoặc class.
Như hình nếu mình có 10 hoặc 20 hàm như này thì phải viết ra như vậy sao như thế rất tệ => cần có function templates.  
   
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/f339caef-6680-4240-bd64-40a5cda8bdb2)

Khai báo một template:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/99f93acf-0d75-4b7a-93d3-be6053b77c04)

Ví dụ:

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/69224cee-3f79-4ee6-9e2f-7a7a265b5745)

### 1. Template parameter by reference
Nhìn đoạn code này ta thật sự thấy thì nó chỉ truyền vào tham trị

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/9d067a5d-947e-4661-a00e-5d9de3a268b4)

Nếu muốn truyền vào tham chiếu thì ta thêm &

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/3e5c685e-49a1-4e0d-9f74-fd62f8ee9939)

### 2. Template Specialazion
Specializing maximum for const char*: độ dài chuỗi kí tự


</p>
</details>

# V models

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/b14f85cc-9791-4e94-8f7b-357abad8195e)

***Quy trình phát triển phần mềm:***
*Requirement:*
   - Thu thập yêu cầu từ khách hàng(đọc kỹ mô tả và các yêu cầu của task).
   - Phân tích tính năng cụ thể.

*Requirement Analysis:*
   - Phân tích cụ thể yêu cầu, hiểu những gì mình phải phát triển.
   - Xác dịnh rủi ro , yêu cu bổ sung nếu cần thiết.

(Liệt kê ra những điều mình biết và chưa biết, ước chừng thời gian để mình thực hiện)
*Design*
- Viết chương trình (build được, ko có lỗi và fix các warning).
- Test Planning: ở trên thì mới viết chương trình nó chạy được thôi nhưng chưa chắc đúng, ở bước này xây dựng sản phẩm dựa trên quy trình thiết kế 

*Development*
- Phát triển sản phẩm

*Unit Test*
- Test từng module

*Integration Test*
- Gôp các module lại vầ Test tính năng hoàn chỉnh để xem nó thực hiện theo luồng hay không.

*System Test*
**




