class A:
    pass

def main():
    dict_a = {}
    dict_b = dict()
    print(type(dict_a))
    print(type(dict_b))

    # set이랑 헷갈릴수 있음
    set_a = {1, 2}
    print(type(set_a))
    # 숫자도 key값 가능
    #  A():4.444 불러올 방법 없음 -> a에 저장
    a = A()
    dict_c = {"a" : 1234, "b" : 897, "c": 876, 1234: 5678, 3.14: 1.111, a:4.444, "1234" : 5679} # A():4.444
    print(type(dict_c))
    print(dict_c)
    print(dict_c[a])
    print(dict_c[3.14])
    print(dict_c["c"])
    print(dict_c["1234"])

if __name__ == "__main__":
    main()