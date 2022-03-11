/* Bạn Bình cầm đầu cả team đi thi đấu giải vô địch Counter-strike toàn quốc.
 Team của Bình rất mạnh nên Bình thích "show-off", nếu trong game này người chơi chuyên nghiệp thường chọn súng trường (rifle) thì Bình lại đi bắn shotgun.

Shotgun có ưu điểm là sát thương cao, bắn trúng gần như chết chắc nhưng ngược điểm tầm bắn ngắn và bắn rất chậm.

Hộc đạn shotgun chứa được m viên, bắn một viên mất r giây. 
Shotgun có 02 cách nạp đạn là thay nguyên hộc đạn mới mất c giây, hoặc nạp từng viên một vào hộc đạn cũ, mỗi viên nạp mất b giây.

Bằng kinh nghiệm chơi lâu năm khéo léo của mình Bình đã vòng ra được sau lưng team địch với một khẩu shotgun đầy đạn. Tất cả n tên địch không để ý tới Bình. Bạn hãy tính toán xem nếu Bình bắn bách phát bách trúng và thì cần tối thiểu bao nhiêu giây để hạ hết toàn bộ team địch. */


#include <iostream>

using namespace std ;

int main()
{
    int b, c, m, n, r ; //Với b là tgian nạp 1 viên
                            //c là tgian nạp cả băng
                            //m là số đạn có trong 1 băng
                            //n là số tên địch
                            //r là tgian bắn 1 viên
    cin >> b >> c >> m >> n >> r ;
    if ( n == 0 )
        {
            cout << 0 ;
            return 0 ;
        }
    int time, left ;
    left = n % m ;
    time = n / m ;
    if ( time == 0 )
        {
            cout << r * n ;
            return 0 ;
        }
    else if ( left * b <= c )
        {
            cout << (time - 1 ) *c + left * b + r * n ;
        }
    else 
        cout << time*c + r*n ;
    return 0;
}