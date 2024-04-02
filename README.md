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
## **LESSION 5: EXTERN - STATIC - VOLATILE - REGISTER**
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

<details><summary>LESSON 5: GOTO - SETJMP</summary>
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

<details><summary>LESSON 6: BITMASK</summary>
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

## **LESSION 7: Struct - Union** 
## **LESSION 8: JSON**
JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/d07554e4-417f-46d6-a95b-e2ec7cc5d5fd)

Có 6 loại định dạng trong JSON: *NULL, NUMBER, ARRAY, STRING, BOOLEAN, OBJECT.*
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/aafc3aad-85d5-49ec-97c3-a840059f4e96)

**một object có thể co nhiều key-value**
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1963a8cf-ce0e-485d-92b3-487d9b8ef317)

</p>

</details>

<details><summary>LESSON 9: LINKED LIST</summary>
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

</p>

</details>


<details><summary>MỘT SỐ THUẬT TOÁN HAY</summary>
</p>

## Câu 1: Tìm giá trị Max của 2 số mà không dùng if else, switch case, toán tử 3 ngôi, toán tử so sánh.
printf("%d" , (a+b+abs(a-b))/2);

## Câu 2: Một số thuật toán sắp xếp
Sắp xết chọn(Selection Sort)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/febde365-f6f9-4446-8daa-37a6909708c9)

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/a96c19dd-e3b3-4335-bc47-0492be6886a1)


</p>

</details>

# ADVANCE C++

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

</p>

</details>
