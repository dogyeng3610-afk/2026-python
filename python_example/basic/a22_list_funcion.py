# c 전역 변수 사용
# # 다른 frame
# var_a = 10
# def make_20(var_a_b):
#     global var_a
#     var_a = 20

# def main():
#     # var_a = 10
#     # ...
#     global var_a
#     make_20(var_a)
#     print(var_a) # 20

# main에 있는 지역변수 변경
# 값이 아닌 list의 메모리 정보가 들어간다.
def make_20(var_a_b):
    var_a_b[0] = 20

def main():
    var_a = 10
    wrapper_list = [var_a]
    make_20(wrapper_list)
    var_a = wrapper_list[0]
    print(var_a) # 20
    # list 이름은 값이 아닌 메모리를 다룸

    list_a = [1, 2, 3]
    list_b = [4, 5, 6, list_a] # 값의 복사가 아니라 메모리 참조

    print(list_b)
    list_a[2] = 30
    print(list_b)


if __name__ == "__main__":
    main()