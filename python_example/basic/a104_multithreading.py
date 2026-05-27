import threading
import time

total = 0
lock = threading.Lock()

# GIL - global interpreter lock : 작업을 수행할 때마다 다른거랑 동시에 실행할 수 없게 한다.
# race condition 항상 주의
# race condition 없애려면 lock, 안전하게 연산
def task(name, duration):
    global total
    print(f"쓰레드 {name} 시작")
    for _ in range(1_000_000):
        with lock:
            total += 1
    time.sleep(duration)
    print(f"쓰레드 {name} {duration}초 후 완료")

# main thread는 그대로, thread 흐름 생김
def main():
    # task("first", 5)
    # task("second", 5)
    threads = []
    for i in range(4):
        t = threading.Thread(target=task, args=(f"T{i+1}", 5+i))
        threads.append(t)
        t.start() # 실제 함수가 실행 되는 라인
    for t in threads:
        # thread 종료를 기다림
        t.join() # block
    print("main은 언제 실행될까요?")
    print(total)

if __name__ == "__main__":
    main()