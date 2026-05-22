def main():
    print("안녕하세요")
    str_var = "안녕하세요"
    print(str_var[0]) # "안"
    print(str_var[1]) # "녕"
    print(str_var[2]) # "하"
    print(str_var[3]) # "세"
    print(str_var[4]) # "요"
    # 요를 여로
    # str_var[5] = "여" # 직접 바꾸는건 안됨
    str_var = str_var.replace("요", "여")
    str_var = "안녕하세요"[:5] + "여"


    # 컨테이너 개수에 맞춰서 돌아감
    # str_var 자리: 컨테이너/range[n]-n번 반복
    for c in str_var: 
        print("for 로 불러온 원소", c)

    # 오버라이딩 문자 3번 반복
    str_var *= 3
    # 슬라이싱 [포함 : 미포함 : step(defalt = 1)]인덱스
    print(str_var[5:10])
    print(str_var[-3:]) # "하세요"
    print(str_var[5:10:2]) #
    print(str_var[-1::-1]) # 거꾸로 출력
    print("str_var 길이", len(str_var))
    print("str_var 길이", str_var.__len__())

if __name__ == "__main__":
    main()