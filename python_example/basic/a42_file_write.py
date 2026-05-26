from pathlib import Path


def main():
    # path = r"/home/dog0/2026/2026-python/python_example/data"
    path = Path(r"/home/dog0/2026/2026-python/python_example/data")
    # f = open(path + '/text.txt', 'w')
    # f.write("Hello Python Programming...!")
    # f.close()

    # with open(path + "/text.txt", "a") as f:
    #     f.write("hello!!!")

    with open(path / 'text.txt', 'a', encoding="utf-8") as f:
        f.write("hello!!!")

if __name__ == "__main__":
    main()