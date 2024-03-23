# ADVANCE C
---

## **LESSION 1: Compiler - Macro**
## **LESSION 2: STDARG - ASSERT**
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

## **LESSION 3: POINTER**
## **LESSION 4: MEMORY LAYOUT**
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
## **LESSION 5: GOTO - setjmp**
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

## **LESSION 6: BITMASK**
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

## **LESSION 7: Struct - Union ** 
## **LESSION 8: JSON **
JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/d07554e4-417f-46d6-a95b-e2ec7cc5d5fd)

Có 6 loại định dạng trong JSON: *NULL, NUMBER, ARRAY, STRING, BOOLEAN, OBJECT.*
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/aafc3aad-85d5-49ec-97c3-a840059f4e96)

**một object có thể co nhiều key-value**
![image](https://github.com/NguyenNgocQuyen29/AdvanceC/assets/124705679/1963a8cf-ce0e-485d-92b3-487d9b8ef317)

## **LESSION 9: LINKED LIST **



