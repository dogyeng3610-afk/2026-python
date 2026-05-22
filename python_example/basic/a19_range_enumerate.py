def main():
    list1 = ['a', 'b', 'c', 1, 2, 3]
    list2 = ["에이", "비", "씨", "one", "two", "three"]

    # python 스타일 = pydentic code
    for ele in list1:
        print(ele)
    
    # c 스타일 = 나쁜 예....
    # i = int()
    # len() 리스트 길이 = 개수
    for i in range(len(list1)):
        print(list1[i])
        print(list1[i], i)
        print(list1[i],list2[i])

    # 루프의 횟수 체크 해야하는 경우 enumerate() 사용
    for i, ele in enumerate(list1):
        print(ele, i)
    for ele1, ele2 in zip(list1, list2):
        print(ele1, ele2)

if __name__ == "__main__":
    main()