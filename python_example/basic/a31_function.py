def print_3_time():
    print("안녕하세요")
    print("안녕하세요")
    print("안녕하세요")

def print_n_time(value : str, n : int) -> str:
    """_summary_
    교육용 테스트 함수이다.
    Args:
        value (str): 출력할 메세지
        n (int): 반복 출력 횟수
    Returns:
        str: 에러 반환
    """
    for i in range(n):
        print(value)
    return "ok"

def main():
    print("첫번째 함수 콜")
    print_3_time()
    print("두번째 함수 콜")
    print_3_time()
    print("세번째 함수 콜")
    print_3_time()

    print_n_time("테스트 텍스트", 7)
    # print_n_time(3, "테스트 텍스트")

if __name__ == "__main__":
    main()