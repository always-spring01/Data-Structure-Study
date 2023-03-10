## Chapter 02
> 순환<br>
Pages : 40 ~ 70<br>
Study Date : 2023.01.20

### 2.1 순환의 소개
>순환이란?

- 순환(recursion)이란, **어떤 알고리즘이나 함수가 자기 자신을 호출하여 문제를 해결하는 프로그래밍 기법**이다.
- 순환은 본질적으로 순환적인 문제나 그러한 자료구조를 다루는 프로그램에 적합하다.
    - 예를 들어, Factorial은 다음과 같이 구상된다.
        - n = 0일 때,   1
        - n >= 1일 때,  n * (n - 1)
    - 즉, 위에서 팩토리얼 n!을 정의하는데, 다시 팩토리얼 (n-1)!이 사용되었다. 이러한 정의를 **순환적이다**라고 한다.
    - 이를 코드로 구현하면 아래와 같다.
            #include <stdio.h>

            int factorial_re(n) {
                if (n == 1) {
                    return 1;
                }else {
                    return n * factorial_re(n-1);
                }
            }

            int factorial(n) {
                int result = 1;
                for (int i = 1; i <= n; i++) {
                    result *= i;
                }
                return result;
            }

            int main(void) {
                int n = 10;
                printf("%d\n", factorial_re(n));
                printf("%d\n", factorial(n));
                
                return 0;
            }
            
    - 위 코드에서는, 순환 (factorial_re), 반복 (factorial) 방식 모두 구현하였다.
    - 팩토리얼 정의 자체는 순환적이나, 알고리즘 속도는 **반복이 더 빠르게** 나온다.
- 속도는 반복(Iteration)이 우세하지만, 가독성 및 이해는 순환(Recursion)이 더 우수하다는 차이가 있다.
- 팩토리얼, 피보나치 수열, 이항계수 계산, 이진 트리 알고리즘, 이진 탐색, 하노이 탑 문제가 순환 알고리즘을 쓰는 것이 자연스러운 알고리즘들이다.
- 예시로 거듭제곱을 구할 때, 순환 알고리즘을 사용한다면 반복 알고리즘에 비해 속도가 비약적으로 향상되는 그 이유는, 순환 호출을 할 때마다 문제의 크기는 약 절반으로 줄어들기 때문이다.
    - 100 > 50 > 25 > 12 > 6 > 3 > 1 (순환)
    - 2^k > 2^k-1 > ... > 2^2 > 2^1 > 2^0 (반복)
- 반대로, 피보나치 수열을 구할 때 순환 구조를 이용한다면, 똑같은 수를 여러 번 계산하여 속도가 반복에 비해 현저히 느려질 수 있다.
- 위와 같이 **문제 알고리즘의 유형에 따라 순환 알고리즘과 반복 알고리즘 중 효율적인 알고리즘이 구분된다**는 점을 항상 명심해야 한다.

### 2.4 하노이탑 문제
>순환의 파워를 가장 극명하게 보여주는 예제

        #include <stdio.h>

        void hanoi_tower(int n, char from, char tmp, char to) {
            if (n == 1) {
                printf("원판 (1) : %c -> %c\n", from, to);
            }else {
                hanoi_tower(n-1, from, to, tmp);
                printf("원판 (%d) : %c -> %c\n", n, from, to);
                hanoi_tower(n-1, tmp, from, to);
            }
        }

        int main(void) {
            hanoi_tower(4, 'A', 'B', 'C');
            return 0;
        }
- 문제는 A, B, C 막대의 A막대에 놓인 원판 n개를 모두 C막대로 이동하는 것이다.
- 이때 다음과 같은 규칙을 지켜야 한다.
    - **한번에 하나의 원판**을 이동할 수 있다.
    - **맨 위에 있는 원판**만 옮길 수 있다.
    - **크기가 작은 원판 위에 큰 원판이** 쌓일 수 없다.
    - **중간에 막대를 임시로 이용할 수 있지만**, 위의 규칙을 지켜야 한다.
- 순환 알고리즘을 사용하면, 다음과 같이 알고리즘을 구성할 수 있다.
    
    1. from의 맨 밑의 원판을 제외한 나머지 원판을 tmp로 옮긴다.
    2. from에 있는 한 개의 원판을 to로 옮긴디.
    3. tmp의 원판들을 to로 옮긴다.
    4. 이때 n == 1이면 from의 한 개의 원판 to로 옮긴다.

- 위 내용을 코드화 하면 앞서 보인 C언어 코드와 동일하다.