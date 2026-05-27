import requests

# async 병렬처리 속도가 더 빠름
def fetch(url):
    response = requests.get(url)
    return response.text

def main():
    html = fetch("http://python.org")
    print(html)

if __name__=="__main__":
    main()