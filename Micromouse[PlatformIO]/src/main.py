# send a request to https://www.jobs.ps/ and display the response

import requests


def main():
    url = 'https://ritaj.birzeit.edu'
    # use a coockie called cf_clearance to bypass the cloudflare protection with the value of the cookie the cockie should be under birzeit.edu domain

    cockie = "PrHsBKYJJfhMNjoaCrsD7aojSEZ8RLWU5D_9_hzGFZ0-1708027550-1.0-AdCtoHEVG7Q3aGKIZfdNLgBUahUYWjRHnDti9n9xS7mPxC32nEDIcNl76sPUhKxSiWG2OcpdVDEg4i1nFuXoN54="

    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
        'cookie': f'cf_clearance={cockie}'
    }

    
    response = requests.get(url, headers=headers)
    print(response.text)

if __name__ == '__main__':
    main()