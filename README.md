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

***Interview Buổi 1***: 17/05/2024 ~ Cố lên Quyên ơi ~
PHÂN VÙNG NHỚNHỚ
## **Câu 1: Sự khác nhau giữa MACRO và FUNCTION và INLINE FUNCTION**

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1ad5ec14-7d7e-4547-9a31-5f275a982c1a)

+ Macro: được xử lí bởi preprocessor, nó đơn giản chỉ là thay thế đoạn code vào chỗ được gọi trước khi biên dịch.
+ Function: được xử lí bởi compiler, khi hàm được gọi thì nó sẽ lưu địa chỉ hiện tại vào stack, rồi nhảy đến hàm được gọi thực hiện và nhận kết quả return, sau đỏ quay lại vị trí trong stack để tiếp tục thực hiện chương trình.
+ Inline: thay thế đoạn mã đã được biên dịch vào chỗ được gọi.
+ Tốc độ: ***Macro > Inline > Function***. Macro thời gian chạy nhanh vì được xử lí ở preprocessor. Inline và hàm tuy đều được xử lí bởi compiler nhưng mà inline nó thay thế đoạn code luôn không cần lưu địa chỉ giống hàm.
+ Kích thước: ***Macro > Inline > Function***. Tại vì hàm chỉ được được dùng mỗi khi gọi thôi.
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

## Câu 3: So sánh Array và con trỏ mảng
- Khi khai báo một mảng thì cho dù mảng đó ở đâu đi chăng nửa thì cũng nằm ở trong 3 vùng đó là Data,BSS,Stack (nếu mảng toàn cục gán giá trị thì ở data, toàn cục chưa khai báo giá trị thì ở bss, hay cục bộ or truyền vào hàm thì cũng nằm ở stack) cả 3 vùng này đều có thể đọc và ghi.

- Con trỏ kiểu char (hay các const): nằm ở vùng text nên chỉ có quyền được đọc , không có quyền được ghi.

## Câu 4: So sánh Malloc và Calloc. Khi nào sử dụng?
Maloc: - cấp phát một vùng nhớ với kích thước là size
       - tham số truyền vào là 1
       - Giá trị khởi tạo là rác

Calloc: - cấp phát vùng nhớ gồm ***num*** phần tử, một phần tử có kích thước là size.
        - tham số truyền vào là 2
        - giá trị khởi tạo là 2

Sử dụng: 
      + Malloc: khi tính toán được kích thước của vùng nhờ cần cấp, khi không quan tâm đến giá trị của vùng nhớ cần khởi tạo thì dùng malloc.
      + Calloc: chỉ cần nhập vào số lượng phần tử và kích thước của mỗi phần tử thì calloc sẽ tự tính toán và cấp phát bộ nhớ cần thiết, khi muốn giá trị mặc định của vùng nhớ cần tạo bằng 0 thì dùng calloc.

Tốc độ: malloc sẽ nhanh hơn vì calloc nó tốn thời gian để khởi tạo giá trị mặc định của các vùng nhớ = 0.
## Câu 5: cho đoạn code:
         int main(int argc, char const *argc[]){
               uint32_t var = 0x01049832;
               (uint8_t)var = ?;
         }

Đáp án: 32

Giải thích:uint8_t chỉ lưu trữ được giá trị 8bit thôi.

STORAGE CLASSES
## **Câu 1: Biến STATIC**
**Static toàn cục(GLOBAL)**: bình thường biến toàn cục có thể được dùng ở file khác dùng các pp như include,extern. Nhưng nếu chỉ muốn biến toàn cục đó dùng trong file hiện tại thôi thì mình sẽ dùng nó chung với từ khóa STATIC. 

**Static cục bộ(LOCAL)**: bình thường một biến cục bộ(nằm trong stack) thì nó sẽ bị thu hồi vùng nhớ khi ra khỏi hàm. Biến static cục bộ nghĩa là khi được khai báo thì biến nó tồn tại trong suốt thời gian thực thi chương trình nhưng chỉ được thực thi trong hàm chứa nó thôi.

## **Câu 2: Biến REGISTER VÀ VOLATILE**

**REGISTER**:Trong khi các biến khai báo trong chương trình thì đặt ở bộ nhớ ngoài (RAM chẳng hạn …). Do đó với khai báo biến thông thường, để thực hiện một phép tính thì cần có 3 bước.
 + Nạp giá trị từ vùng nhớ chứa biến vào 
 + Yêu cầu ALU xử lý register vừa được nạp giá trị.
 + Đưa kết quả vừa xử lý của ALU ra ngoài vùng nhớ chứa biến.
Khi thêm từ khóa register để khai báo biến, thì tức là ta đã yêu cầu trình biên dịch ưu tiên đặc biệt dành luôn vùng register để chứa biến đó. Và hiển nhiên khi thực hiện tính toán trên biến đó thì giảm được bước 1 và 3, giảm bớt thủ tục vậy nên hiệu năng tăng lên.
  
**VOLATILE**: Một biến cần được khai báo dưới dạng biến volatile khi nào? Khi mà giá trị của nó có thể thay đổi một cách không báo trước. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler. 3 ví dụ trong thực tế nên dùng biến volatile
 + Memory-mapped peripheral registers (thanh ghi ngoại vi có ánh xạ đến ô nhớ)
 + Biến toàn cục được truy xuất từ các tiến trình con xử lý ngắt (interrupt service routine)
 + Biến toàn cục được truy xuất từ nhiều tác vụ trong một ứng dụng đa luồng.

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
OOP
+ Tình đóng gói:ẩn đi property mật khỏi người dùng ở chế độ private, muốn đọc ghi thì phải truy cập các method ở quyền public
   
+ Tính trừu tượng: ẩn đi các cái chi tiết và chỉ trưng bài nhưng cái cần thiết. Ví dụ: giải nghiệm phương trình bậc 2, thì khai báo biến và giải chi tiêst sẽ được ẩn đi ở private và ở public chỉ trưng bày những method ví dụ như truyền vào các hệ số của chương trình bậc 2, và print ra nghiệm của pt bậc 2.
***=> Tính đóng gói ẩn đi để bảo vệ dử liệu, còn tính trừu tượng ẩn đi cái không cần thiết.***
- Những vấn đề ở trính đóng gói giải quyền bằng cách thao tác giữa các cái method ở public, còn trừu tượng thì giải quyết ở những cái trưng bày lên.

+ Tính kế thừa: một lớp mà sử dụng lại các property của một lớp khác gọi là kế thừa. Ví dụ code: một class Person có các đặc tính như: tên, tuổi ,quê quán. Một class Student kế thừa từ class này ngoài có những đặc điểm riêng như: tên trường, MSSV, GPA thì nó còn có những property của lớp cha mà nó kế thừa.
  
+ Tính đa hình: tức là một lúc có thể thực hiện nhiều form. Nó sử dụng các class được kế thừa để sử dụgn nhiều tác vụ khác nhau.
  Ví dụ: trong 1 class , có nhiều hàm summ, ham thì truyền vào 2 tham số, có hàm truyền vào tham số....
  Đa hình: có 2 loại đa hình tĩnh(compiler time) và đa hình động (runtime)
  + Đa hình tĩnh: function overloading và operator overloading
  + Đa hình động: function overriding

  => Đa hình tĩnh không thực hiện được tính đa hình thông qua kế thừa. Còn đa hình động có thể thực hiện đa hình thông qua kế thừa (overriding, ví dụ: có 1 class con kế thừa từ class cha, class cha có 1 hàm sum rồi, class con cũng có thể định nghĩa lại 1 hàm sum khác 1 lần nữa)
***=> Tính đa hình chủ yếu dùng cho các method, tính kế thừa dùng cho các class***

#### Câu 1: Có 2 class B,C kế thừa từ class A, class D kế thừa từ class B,C có được không?
Câu trả lời là được, đó là 1 loại của kế thừa: Mutipath Inheritance.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/5608640a-1f35-4597-ac59-195e6cbed849)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/5b053567-45aa-4e9a-95a0-94945571bbef)

- Tại sao có thể truy cập trực tiếp các method nhưng method display phải dùng thêm class , ví class D kế thừa từ B,C (directly) từ A(indirectly), cả 3 class này đều có method display(), nên nếu chỉ ghi là m.display() thì complier sẽ không biết mình đang invoke cái method nào.


 ### OOP1. Inheritance
 - Nó kế thừa tính năng của một lớp khác, sử dụng các property và method của class, để kế thừa ta dùng

 - Class cho kế thừa gọi là class cha, còn class được kế thừa gọi là class con.

 - Class con có theer truy cập các thuộc tính của class chả kể cả private và protected.
   
 - Nó bao gồm các loại:
          - Single: A derived class with only base class is called inheritence.
          - Multilevel: A derived class with a base class and that base class is derived class of another 
          - Multiple: A dirived classes with multiple base class. 
          - Heritical:  Multiple dirived classes with same base class.
          - Hybrid: kết hợp Multiple và Heritical
          - Multipath: a derived class with two base class and two base class have one common base class.

Mode of inheritance:
+ public( visible to everyone)
+ protected ( visible to current class and derived class only)
+ private ( visible to current class only).

- Ví dụ: mình có 1 class Person có các đặc điểm như tên, tuổi ,địa chỉ nhà, Một class Student kế thừa từ class Person , class này vừa có đặc tính của class cha và vừa có những đăc tính riêng của nó như tên trường, GPA, ID. Tức là class kế thừa gồm các đặc tính từ lớp nó kế thừa và những đặc tính riêng nữa. 

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/9130de02-e454-44a3-8d90-c1a3bd4b1988)  ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/4b603d3f-b3a4-4916-9363-390ae547f7c7)



### OOP. Polimorphism
Có  2 loại polimorphism
- Compiler Time Polimorphism
  + Function Overloading
  + Operator Overloading
- Runtime Polimorphism
  + function overriding (using virtual functions)
 
**Vitual Function**
1. Vitual Function cann't be static and also can be a friend function of another class.
2. A class can have virutal destructor but can't have vitual constructor.
3. Cấc hàm ảo phải được truy cập bằng con trỏ hoặc tham chiếu lớp cơ sở mới đạt được tính đa hình khi chay.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/9227809c-e7a1-465a-9e10-e8c6024a9c1e)

   
5. There are two types of vitual function in C++
   
         + Vitual Function: hàm ảo là hàm đã được khai báo ở lớp  và được định nghĩa lại ở lớp con.
   
         + Pure Vitual Function

   ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/7ab1b262-3dfa-437e-b5b6-eb5586d1e466)

### OOP3. Encapsulation
Là ẩn đi các properties mật khỏi người dùng, các properties này sẽ được cấp quyền truy cập là private.
Nếu muốn đọc hoặc ghi các properties này thì ta cấp các method ở public.

- Ví dụ: một class có các properties ở chế độ bảo vật như: tên sinh viên, điểm. mã số SV.
- Muốn ghi hoặc đọc các properties này thì chúng ta sẽ tạo ra các method để thao tác hoặc các constructor.

  ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/936429f1-3a69-4ff6-a0d9-ff2dea0032bf)

  ### OOP4. Abstraction
  Tính trưu tượng là ẩn đi các chi tiết cụ thể và chi trưng bày những gì cần thiết để sử dụng đối tượng.
  - Ví dụ: một class có các property private là các hệ số của ptrinh bậc 2 và cách tính nghiêm của  phương trình bậc 2.
  - Những cái này sẽ đươhc ẩn đi, và trưng bày nhưunxg thông tin cần thiết ví dụ như: method điền các hệ số a,b,c và in ra kết quả

    ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/c2e189c4-1cdb-4662-b635-17300a7d197b)

    ![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/d98fb677-5cc4-4b84-9f55-f49e1a8e355a)


</p>
</details>

<details><summary>LESSION15: STL</summary>
</p>

STL - Standard Template Library là một thư viện trong ngôn ngữ lập trình C++ cung cấp một số tập hợp các template classes và function để  thực hiện các cấu trúc dữ liệu và một số thuật toán phổ biến.
Một số thành phần chính của STL:
+ Container
+ Iterator
+ Algorithms
+ Funtor

**Container** là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể . Một số container tiêu biểu:
- Vector
- Map
- List
- Array

*Vector* là một trong những container quan trọng nhất của C++. Nó cấp một mảng động với khả năng thay đổi kích thước một cách linh hoạt.

<details><summary>V models</summary>
</p>

<details><summary>LESSION15: MULTITHREADING</summary>
</p>


<details><summary>V models</summary>
</p>
   

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

</p>
</details>



