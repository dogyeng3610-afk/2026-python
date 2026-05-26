import datetime

def main():
    # list 선언
    list_a = []
    # class 방식으로 선언가능
    list_b = list()
    # 선언과 동시 정의
    list_c = [1, 2, 3, 4, 5, 6]

    print(list_a, list_b, list_c)
    print(type(list_a), type(list_b), type(list_c))
    # 사용자 정의
    ptime = datetime.datetime.now()
    list_d = [1, 2, 3.151592, "kim", ptime]
    print(list_d)
    print(list_d[3])
    list_d[3] = "do"
    print(list_d[3])

    list_e = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]
    print(list_e)
    print(list_e[1][1])

if __name__ == "__main__":
    main()