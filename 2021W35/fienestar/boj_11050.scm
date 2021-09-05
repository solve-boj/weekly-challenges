; 이항 계수 1
; https://www.acmicpc.net/problem/11050
(define(c n r)(cond((= r 0)1)((= n r)1)(#t(+(c(- n 1)(- r 1))(c(- n 1)r)))))(write (c (read) (read)))