# -*- coding: utf-8 -*-
"""
Created on Sun Feb  7 10:18:37 2021

@author: ojas
"""
import requests
from bs4 import BeautifulSoup
headers = {"Accept-Language": "en-US, en;q=0.5"}
i=1
url = "https://codeforces.com/problemset/page/"+str(i)
results = requests.get(url,headers = headers)
links = []
while(results):
    soup = BeautifulSoup(results.content,'html.parser')
    if(len(links)>1 and links[-1]==links[-2]):
        break
    link = []
    table = soup.select('.problems')
    a_tags = table[0].select('.id')
    for ac in a_tags:
        link.append('codeforces'+str(ac.a['href']))
    links.append(link)
    i+=1
    res = results
    url = "https://codeforces.com/problemset/page/"+str(i)
    results = requests.get(url,headers = headers)
links.remove(links[-1])
print(links)