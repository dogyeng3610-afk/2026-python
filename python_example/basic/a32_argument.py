def print_n_time(n : int, *value : str) -> str:
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
    return "ok", n

def main():
    print_n_time(3, "abc", "def", "ghi", "ddd") # ('abc', 'def', 'ghi') 튜플
    return_var = print_n_time(3, "abc", "def", "ghi", "ddd")
    print(*return_var)

if __name__ == "__main__":
    main()