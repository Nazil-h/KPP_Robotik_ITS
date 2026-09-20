# KPP Robotics Maze

Project ini berisi kontroling Robot (R) menggunakan input UP, DOWN, RIGHT, LEFT, dengan menggunakan bahasa C++ disertai library <iostream>, <string>, dan <cstdlib>.

## Note
R : Berperan sebagai *ROBOT* yang dapat digerakkan atau dikontrol sesuai input user (UP, DOWN, RIGHT, LEFT).
S : Sebagai penanda titik *START* atau titik mulai Robot berjalan.
F : Sebagai letak *FLAG* yang dapat diambil oleh sang Robot dan flag tersebut menjadi syarat agar dapat menyelesaikan misi saat menuju titik goal.
G : Sebagai penanda titik *GOAL* yang berperan menjadi titik akhir atau tujuan Robot dalam misi ini.
X : Sebagai penanda titik *LAND MINE* atau biasa disebut jebakan yang tidak dapat dilewati oleh sang Robot.
'#' : Berperan sebagai *dinding* yang tidak dapat dilewati maupun ditembus oleh sang Robot.
'.' : Sebagai penanda *jalan* bahwa titik tersebut dapat dilewati oleh sang Robot.
STEP ".." : Sebagai penanda berapa *step* yang telah dilakukan oleh sang Robot.
MOVE "..." : Berperan sebagai *output arah* gerak robot sebelumnya yang telah diinput.
POSITION (.,.) : Berperan sebagai *titik koordinat* Robot saat berada di Maze.

== Input yang tersedia == :
'UP'   : Menggerakkan Robot ke atas dengan eksekusi y - 1.
'DOWN'   : Menggerakkan Robot ke bawah dengan eksekusi y + 1.
'RIGHT'   : Menggerakkan Robot ke samping kanan dengan eksekusi x + 1.
'LEFT'   : Menggerakkan Robot ke samping kiri dengan eksekusi x - 1.
'QUIT'   : Untuk mengakhiri program (keluar) sebelum misi selesai.

## Tutorial
1. Saat user memulai program, akan keluar bentuk *MAZE* yang akan Robot hadapi.
2. User dapat menginput "UP, DOWN, RIGHT, LEFT" untuk menggerakkan Robot, dan dapat keluar dari program dengan cara menginput "QUIT".
3. Tujuan pertama user yakni menggerakkan Robot menuju titik *F* hingga mendapatkan FLAG dengan tanpa melewati tanda *X* maupun tanda *#*.
4. Setelah mendapat FLAG yang ditandai dengan output [FLAG CAPTURED], user sekarang memiliki misi yakni menuju titik *G*.
5. Setelah mencapai titik G user akan mendapat output "MISSION COMPLETE" yang berarti telah berhasil menyelesaikan maze tersebut dan telah keluar dari program.