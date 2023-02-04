# Data-Structure-Study
## C 언어를 이용하여 공부한 자료구조 코드 & 해설 정리
> 책 : C언어로 쉽게 풀어쓴 자료구조
<br>공부 시간 : 평일/주말 매일 1시간 (30m 복습, 30m 공부)

### Chapter 01. 자료구조와 알고리즘
- cal_scores.c : 입력된 scores중 최대값을 찾아내는 간단한 알고리즘 실습
- cal_time.c : 알고리즘 수행 시간을 컴파일러를 통해 계산하는 코드 실습

### Chapter 02. 순환
- hanoi.c : 하노이탑 알고리즘을 순환 기법으로 풀이한 코드
- factorial.c : factorial을 순환 기법으로 풀이한 코드

### Chapter 03. 배열, 구조체, 포인터
- structure.c : 구조체와 typedef 키워드를 이용한 사용자 정의 자료형 생성 예제
- point.c : 본문 75쪽의 Quiz 해설 답안
- polynomical.c : 구조체를 이용해 다항식 연산을 하는 프로그램 예제
- polynomical2.c : 구조체를 응용해서 새로운 다항식 연산을 하는 프로그램 예제
- matrix1.c : 2차원 배열을 이용해 전치 행렬을 구하는 프로그램 예제
- matrix2.c : 구조체를 응용하여 희소행렬에 메모리 낭비 없는 행렬의 전치 행렬을 구하는 프로그램 예제
- swap.c : 포인터를 활용해 함수 내부에서 외부 변수를 변경하는 프로그램 예제
- malloc.c : malloc() / free() 함수를 사용해 힙 메모리의 동적 메모리를 할당받아 정수형 변수를 생성하는 예제
- malloc2.c : 동적 메모리를 사용하는 또 다른 예제

### Chapter 04. 스택
- arrstack.c : array로 구현한 스택
- structstack.c : struct로 구현한 스택
- stack.c : pointer를 활용해서 스택을 전역변수가 아닌 형태로 구현함 (객체지향적)
- stack2.c : malloc(), realloc() 함수를 활용하여 스택의 크기를 동적으로 조절할 수 있도록 구현
- opendoorstack.c : 스택을 활용한 괄호검사 프로그램