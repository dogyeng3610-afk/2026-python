import random

def main():
    # 결과 for 변수 in 컨테이너 if 조건
    # 조건 -> 결과 -> 컨테이너
    li = [(i + 1) for i in range(100) if i % 2 == 0] # 짝수 -> i + 1 -> 리스트
    print(li)
    # list 섞기
    random.shuffle(li)
    print(li)
    # 최소값, 최대값, 총합
    print(min(li), max(li), sum(li))
    # 오름차순
    li.sort()
    print(li)
    # 내림차순
    li.sort(reverse=True)
    print(li)

    


if __name__ == "__main__":
    main()