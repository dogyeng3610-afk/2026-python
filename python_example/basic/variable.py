def main():
    # 선언 필요 x 선언을 한다면 : int_a = int()
    int_a = 10
    print(int_a)
    print(type(int_a))
    int_a = "ten"
    print(int_a)
    print(type(int_a))

    # 변수명, 함수명 a_b_c ... thePythonClass -> 식별자 / python은 대부문 snakecase 사용
    # cnovention 개발자 규칙
    # 변수명 함수명 -> 소문자 시작
    # 클래스명 -> 대문자 시작, bulith-in은 소문자 시작

    

# import를 당했을 때  __main__이 아니게 된다.
if __name__ == "__main__":
    main()