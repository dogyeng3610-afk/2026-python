def print_n_time(
        *value : str,
        n : int = 2,
        i_var = 4
) -> str:
    """_summary_
    교육용 테스트 함수이다.
    Args:
        n (int): 반복 출력 횟수
        value (str): 출력할 메세지
    Returns:
        str: 에러 반환
    """
    print(type(value)) # <class 'tuple'>
    # temp1, temp2, temp3 = value
    # (temp1, temp2, temp3)소괄호 생략-튜플 = (first, second, third)
    for i in range(n):
        print(value)
        # print("first", temp1, "second", temp2, "third", temp3)
        for v in value:
            print(v, end=" ") 
        print("\n\n")
    print("i의 값은: ", i_var)
    return "ok"

def print_keyward_argument(a, b, c, d=5, *e): # 1 2 3 4 (5, 6, 7) d=4
    print(a, b, c, d, e)

def main():
    return_var = print_n_time("abc", "def", "ghi", "ddd")
    # keyward_argument 꼭 지정
    return_var = print_n_time("abc", "def", "ghi", "ddd", n = 4)
    return_var = print_n_time("abc", "def", "ghi", "ddd", n = 4, i_var=8)
    return_var = print_n_time("abc", "def", "ghi", "ddd", i_var=8, n = 4)
    print(type(return_var))
    print(*return_var)

    # default_argument 자리수, 생략해도 나옴, 덮어쓰기 가능
    print_keyward_argument(1, 2, 3, 4, 5, 6, 7)
    print_keyward_argument(1, 2, 3)

if __name__ == "__main__":
    main()