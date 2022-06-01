# <u>GAME PROJECT : TINY FOO</u>



###### Thông tin sinh viên:

> ​	**Họ và tên:** Đinh Đức Thuận 
>
> ​	**MSSV:** 21020795
>
> ​	**Lớp thực hành:** INT2215_9
>
> ​	K66CD - CN1 - UET. 
>
> ​	**github:** stkey002
>
> ​	**youtube:** FOO IN DA BAR

***

## MỤC LỤC

1. [TỔNG QUÁT](#TONG-QUAT)
   * [Luật chơi](###Luat-choi)
   * [Cách chơi](#Cach-choi)
   * [Hướng dẫn tải game](#Huong-dan-tai-game)
   
2. [MÔ TẢ CHỨC NĂNG](#MO-TA-CHUC-NANG)
   * [Video mô tả chức năng](#Video mô tả chức năng)
   
3. [KĨ THUẬT LẬP TRÌNH ĐÃ ĐƯỢC SỬ DỤNG](#Kĩ thuật lập trình đã được sử dụng)

4. [KẾT LUẬN](#KẾT LUẬN)

   * [Hướng phát triển](#Hướng phát triển)

   * [Những điều tâm đắc](#Những điều tâm đắc)

5. [LỜI CẢM ƠN](#LỜI CẢM ƠN)

## TỔNG QUÁT:

- **Tên game:** TINY FOO
- **Thể loại:** Khéo léo, hành động, phản xạ
- **Chế độ:** offline
- **Đồ hoạ:** 2D
- **Ngôn ngữ lập trình:** C/C++
- **Thư viện đồ hoạ:** SDL 2.0
- **Game được phát triển bằng IDE Microsoft Visual Studio 2022**

![image](https://user-images.githubusercontent.com/67379909/170853227-7f6f9b47-2a21-4ae4-af14-829f8bc6b20b.png)



​	Tiny Foo là tựa game né vật thể, đòi hỏi sự khéo léo và tập trung cao độ của người chơi.

​	Hoàn cảnh ra đời: Tiny Foo là một tựa game được phát triển hoàn toàn dựa trên ý tưởng sáng tạo ban đầu của sinh viên lập trình. Nguồn cảm hứng đặt tên game là từ kích thước tí hon của nhân vật game (tiny) và tên đại diện được sử dụng nhiều nhất trong ngành công nghệ: Foo (trong Foobar).

### Luật chơi:

​	Trong Tiny Foo, người chơi sẽ nhập vai vào một nhân vật tí hon có ***<u>DUY NHẤT MỘT SINH MẠNG</u>***. Nhiệm vụ của người chơi là né những viên đá từ trên không trung rơi xuống và phá vỡ kỉ lục tính theo thời gian đã từng tồn tại trước đó. 

##### Ý tưởng kích thích người chơi: 

1. Nhân vật game chỉ có một sinh mạng và không có bất kì hiệu ứng buff, do đó người chơi sẽ phải tập trung nếu muốn phá vỡ kỉ lục.

2. Mặc dù vị trí và tốc độ đá được chọn random nhưng các cấp độ game được thiết lập theo các mốc thời gian. Cụ thể, cứ sau các mốc thời gian, số lượng đá sẽ được tăng lên, người chơi phải di chuyển nhiều hơn.

3. Lập trình viên đã giấu một đoạn code có chức năng tự sinh đá rơi trúng vào vị trí nhân vật sau một khoảng thời gian ngắn => gây khó khăn cho những người chơi phong cách núp hoặc sử dụng "nhân phẩm"....

   

### Cách chơi: 

* Nhấn : **A** hoặc **MŨI TÊN SANG TRÁ**I để chạy sang trái

* Nhấn : **D** hoặc **MŨI TÊN SANG PHẢI** để chạy sang phải

![tutorial_ground](https://user-images.githubusercontent.com/67379909/170853246-aed89008-3d87-4cf7-9aed-fd27187e14cc.png)



### Hướng dẫn tải game:

> Lưu ý: Quá trình tải game được thử nghiệm thành công trên hệ điều hành window. Khuyến nghị sử dụng hệ điều hành window10 để thực hiện

1. Bấm [vào đây](https://github.com/stkey002/TinyFoo/archive/refs/heads/master.zip) để tải trực tiếp dự án

2. Tới thư mục lưu dự án, giải nén file **TinyFoo-master.zip**

3. Sau khi giải nén xong, vào folder TinyFoo-master. Giải nén file **LibSdl2.zip**

4. Đối với hệ điều hành người dùng là:  

   * window 32bit (x86): Giải nén **TinyFoo_x86.zip**, sau đó vào folder Release --> chạy TinyFoo.exe để trải nghiệm ứng dụng

     > Đường Link mô phỏng: C:\Users\Administrator\Downloads\ **TinyFoo-master\Release**
     >
     > ![image](https://user-images.githubusercontent.com/67379909/170853667-72464d6d-69f4-44f5-accd-e2a61c5c41b9.png)

   * window 64bit (x64): Giải nén **TinyFoo_x64.zip**, sau đó vào folder x64 --> Release --> TinyFoo.exe để trải nghiệm ứng dụng

     > Đường Link mô phỏng:  C:\Users\Administrator\Downloads\ **TinyFoo-master\x64\Release**
     >
     > ![image](https://user-images.githubusercontent.com/67379909/170853742-8e3861eb-6fcb-49d2-b0ac-9c989fc97583.png)

**<u>NOTE</u>** : Nếu xuất hiện thông báo lỗi VCRUNTIME140 và không chạy được TinyFoo.exe, hãy ấn vào đây để tải và cài thêm Microsoft Visual C++ Redistributable. Nguồn https://docs.microsoft.com/vi-VN/cpp/windows/latest-supported-vc-redist?view=msvc-170

* Đối với x86: https://aka.ms/vs/17/release/vc_redist.x86.exe
* Đối với x64: https://aka.ms/vs/17/release/vc_redist.x64.exe

Game hiển thị tốt nhất với màn hình có tần số quét 60Hz, để có trải nghiệm chơi tốt nhất nên thiết đặt tần số quét của màn hình là 60Hz theo hướng dẫn sau:

1. Chọn Start -> Setting hoặc Window + I để mở hộp thoại Setting.
2. Tại hộp thoại Setting chọn System -> Display -> Advanced display setting.
3. Tại mục Refresh Rate, chọn tần số 60Hz.

<u>**MUỐN XEM PROJECT CỦA DỰ ÁN (Áp dụng cho một số phiên bản Visual Studio)**</u>: Quay trở lại thư mục **TinyFoo-master**. Chọn **TinyFoo.sln** , đấy là nơi quản lí toàn bộ dự án. Muốn chạy Release x64/x86 ở trong Visal Studio thì  **LibSdl2.zip** và **TinyFoo_x64.zip**(tương tự với **TinyFoo_x86.zip**) phải được giải  nén thành công trước.

> ![Untitled](https://user-images.githubusercontent.com/67379909/170854107-6fd99753-089a-4958-baa3-e2e333ef1987.png)
>
> Forder TinyFoo-master cần đầy đủ như này để thực hiện được makefile trong Visual Studio.

> ![image](https://user-images.githubusercontent.com/67379909/170854154-a6f915df-3b99-429f-a61a-bec405f93011.png)





## MÔ TẢ CHỨC NĂNG



### **Video mô tả chức năng:** 

Youtube: [TINY FOO: Lối chơi và một số chức năng của game!!](https://www.youtube.com/watch?v=RCO6bGGDKf8)



### CƠ CHẾ HOẠT ĐỘNG CỦA GAME: 

* Sử dụng class `CHARACTER`: để quản lí nhân vật game

  * Toạ độ nhân vật

  - Vận tốc nhân vật
  - Thao tác bàn phím với nhân vật
  - Sự di chuyển của nhân vật

* Sử dụng class `ROCK`: để quản lí các thuộc tính và phương thức của viên đá

  * Toạ độ sinh vật thể: sử dụng hàm `rand() ` 

    ```C++
    int pos = rand() % (SCREEN_WIDTH - ROCK_WIDTH);
    ```

  * Vận tốc của vật thể: sử dụng hàm `rand()` 

    ```C++
    short speed = rand() % 11 + 8;
    ```

* Sử dụng hàm `checkCollision()` để bắt va chạm các vật thể:

  ```C++
  bool checkCollision(SDL_Rect a, SDL_Rect b)
  {
  	//The sides of the rectangles
  	int leftA, leftB;
  	int rightA, rightB;
  	int topA, topB;
  	int bottomA, bottomB;
  
  	//Calculate the sides of rect A
  	leftA = a.x;
  	rightA = a.x + a.w;
  	topA = a.y;
  	bottomA = a.y + a.h;
  
  	//Calculate the sides of rect B
  	leftB = b.x;
  	rightB = b.x + b.w;
  	topB = b.y;
  	bottomB = b.y + b.h;
  
  	//If any of the sides from A are outside of B
  	if (bottomA <= topB) return false;
  	if (topA >= bottomB) return false;
  	if (rightA <= leftB) return false;
  	if (leftA >= rightB) return false;
      
  	return true;
  }
  ```

  

* **SỰ KIỆN CHUỘT**:  Sử dụng một class `MENU` để quản lí các biến class `BUTTON`.  `Menu` gồm có: 

  * **START_SCREEN**:
    * PLAY: Bắt đầu vào trò chơi
    * TUTORIAL: Hướng dẫn nhanh cho người mới chơi
    * QUIT: Thoát game
    * RANK (góc dưới phải màn hình): Xem điểm cao nhất từ trước
    * MUSIC (góc dưới phải màn hình): Bật/ tắt âm nhạc của game
  * **PLAY_SCREEN**
    * PAUSE (ở góc phải màn hình): Tạm dừng trò chơi
    * Hiển thị thời gian (điểm) mà người chơi đạt được
  * **PAUSE_SCREEN**
    * CONTINUE: Tiếp tục trò chơi
    * BACK: Trở về màn hình **START_SCREEN**
    * MUSIC
  * **LOSING_SCREEN**
    * RESTART: Chơi lại game mới
    * BACK
    * Hiện số điểm người chơi đạt được

* **<u>Âm thanh: Sử dụng nhạc nền và soud effect khác nhau, thay đổi theo từng SCREEN của Game (3 Screen).</u>**

* **<u>Hiển thị phần điểm số ở màn hình Game Over.</u>**

* <u>**Nếu điểm số cao hơn phần kỉ lục, thì điểm số ở phần kỉ lục sẽ được thay đổi.**</u>



## KĨ THUẬT LẬP TRÌNH ĐÃ ĐƯỢC SỬ DỤNG

* Chia tách FILE: Code sạch đẹp, dễ quản lí

* Header Guard: Không bị lặp lại khai báo file.h

* Lập trình OOP với Class và các đặc tính như Đóng gói, Kế thừa, Đa hình, Trừu tượng: quản lí đối tượng dễ dàng và sạch đẹp (LTexture quản lí hình ảnh, Character để quản lí nhân vật, LTime để quản lí thời gian,...)

* Cắm cờ Flag : kiểm tra đúng sai trong 1 hàm nhiều điều kiện

* //Comment

* Khai báo, sử dụng, và giải phóng các biến con trỏ

* Dùng Vector kiểu con trỏ class: `static vector<ROCK*> list_rock;`

* Sử dụng biến tham chiếu reference không phát sinh bộ nhớ

* Linh hoạt sử dụng hàm bool, biến bool như các công tắc Bật/Tắt

* Sự kiện chuột, bàn phím

* Bắt va chạm giữa các vật thể

* Chạy Sprites của nhân vật theo từng status chuyển động : Đứng im(IDLE), Chạy(RUN)

* Stringstream

* Đọc, ghi file : ghi điểm cao

* Sinh số ngẫu nhiên

* Liệt kê bằng enum

* Sử dụng các hàm trong các thư viện chuẩn của C/C++

* Sử dụng các hàm trong các thư viện đồ hoạ SDL 2.0



## KẾT LUẬN

* Việc phát triển và hoàn thành dự án game TinyFoo giúp em đạt được nhiều kinh nghiệm về mọi mặt nói chung và kĩ năng trong công nghệ thông tin nói riêng. Rèn luyện cho em tư duy phân bổ công việc, giải quyết các vấn đề một cách nhẫn nại, hợp lí, logic và tuần tự. Nắm thêm được các công đoạn làm game 2D cơ bản giúp em có thể tự mình tạo ứng dụng GUI, bổ trợ kiến thức cho những môn học và công việc sau này.

### Hướng phát triển thêm

* Dự kiến thêm tính năng thay đổi nhân vật trước khi vào game

* Thêm một số loại vật thể rơi, thay đổi kích thước cho đa dạng

* Tạo các động tác nhảy, lướt

* Update một vài tính năng khả thi trong kho tài liệu của LazyFoo

* Thêm hiệu ứng đồ hoạ hấp dẫn hơn

### Những điều tâm đắc:

* Trước khi thực hiện bài tập, những kĩ năng em đã có như lập trình cơ bản, đọc hiểu tiếng anh, sử dụng công cụ tìm kiếm google, photoshop, chuyển đổi âm nhạc, github,... có cơ hội tiếp tục mài giũa và phát triển.
* Trong quá trình làm bài tập, em đã tự mình làm quen và thành thạo được với Microsoft Visual Studio 2022, một IDE mạnh mẽ đối với lập trình viên. Có cơ hội tiếp cận với một số phần mềm đóng gói ứng dụng như Advanced Installer, MVS Installer Project, phần mềm ghi chú code và một số phần mềm hỗ trợ Tile map.
* Em đã nỗ lực tìm kiếm tài nguyên hình ảnh, âm thanh <u>miễn phí trên internet</u> sao vừa phù hợp với hiển thị nhân vật, bối cảnh game, vừa có thể để code xử lí ở phía sau một cách mượt mà.
* Trong khoảng thời gian đầu, việc học lí thuyết và tìm hiểu những câu lệnh mới khiến em mất rất nhiều thời gian. Sau đó là cách trình bày và ứng dụng thuật toán sao cho mọi thứ hợp lí, hiểu quả và không bị lỗi. Việc làm game SDL khiến em rèn luyện được tính tập trung, tính kỉ luật và kiên trì của bản thân trong công việc.



## LỜI CẢM ƠN

Em xin gửi lời cảm ơn chân thành và sâu sắc nhất tới các thầy giáo phụ trách giảng dạy môn lập trình nâng cao:

* **Thầy Trần Quốc Long**

* **Thầy Nguyễn Việt Anh**

* **Thầy Nguyễn Hoàng Minh Công**

đã hỗ trợ, giúp em hoàn thành bài tập lớn này.



***Đồng thời cảm ơn tới:***

* [Lazy Foo's Productions](https://lazyfoo.net/)

* [Phát Triển Phần Mềm 123 AZ](https://phattrienphanmem123az.com/)
* Cộng đồng [321B](https://www.codehub.com.vn/)

* Cộng đồng [StackOverFlow](https://stackoverflow.com/)

***Tài nguyên:***

* [https://wiki.libsdl.org](https://wiki.libsdl.org/)

* https://free-game-assets.itch.io/free-tiny-hero-sprites-pixel-art

* https://brawlhalla.fandom.com/wiki/Twilight_Grove

* https://www.brawlhalla.com/wallpapers/
* www.youtube.com
* www.google.com

























