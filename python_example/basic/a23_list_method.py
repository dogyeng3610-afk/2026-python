import datetime

def main():
    list_a = [1, 2, 3]
    list_b = [4, 5, 6]
    # + : method
    # return 결과 수정
    print(list_a + list_b)
    print(list_a.__add__(list_b)) # cpp의 연산자 오버로딩

    # list 자체 수정
    print(list_a := list_a.__add__(list_b)) # elephant sign 값 수정
    list_a.extend(list_b) # expend는 return없음
    print(list_a)

    # * 연산 
    print(list_a * 4)
    print(list_a.__mul__(4))

    # append 맨 뒤 원소 추가
    list_b.append("추가 원소") # type: ignore
    print(list_b)

    # insert 중간 삽입 (인덱스지정, 들어갈 값)
    list_b.insert(3, 7)
    print(list_b)

    # 삭제 - 인덱스, 값(value) 지정 
    print(list_b.pop()) # 한번쓰고 버릴 때 사용
    # 순회는 for
    print(list_b)
    print(list_b.pop(0)) # default -1, -1은 맨 뒤
    print(list_b)
    list_b.remove(6)
    print(list_b)

    # list 검색
    print(list_b.index(7)) # 1
    print(list_b[list_b.index(7)]) # 7
    list_b = ["a", "b", "c", "d", "e", "f"]
    list_e = [*str("abcdefkim do gyeong")] # 띄어쓰기 포함
    print(list_b.index("e"))
    print(list_e)
    print(list_e.__len__())
    print(len(list_e))
    
    print("k" in list_e)
    print("q" in list_e)

    # 메모리 삭제
    # del
    del list_e[4]
    # 사용자 정의 타입인경우는 list에서만 삭제 됨
    # del 사용자 정의 타입 삭제하는 경우
    print(list_e)
    ptime = datetime.datetime.now()
    list_e.append(ptime) # type : ignore
    print(list_e[18])
    del list_e[18]
    # 따로 삭제 필요
    del ptime
    print(list_e)
    print(ptime)

if __name__ == "__main__":
    main()

