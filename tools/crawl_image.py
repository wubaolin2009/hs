# -*- coding: utf-8 -*-
__author__ = 'Baolin Wu'

import httplib,urllib
import re
import chardet

def fetch_html(page):
    # extract a valid address
    host = page.split('/')[0]
    url = '/'.join(page.split('/')[1:]) if len( page.split('/')) > 1 else ''
    headers = {"Host": host,
               "User-Agent": "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.1) Gecko/20090624 Firefox/3.5",
                "Accept": "text/plain"}

    http_client = httplib.HTTPConnection(host)
    http_client.request('GET', '/' + url, headers=headers )
    response = http_client.getresponse()

    if response.status != 200:
        response.read()
        print 'Response Error'
        return None
    s = response.read()
    s = s.replace("\r\n"," ")
    return s

def extract_image(html):
    pattern_str = "/db/images/z_t_js/z_t_jk_js/"
    result = re.findall(pattern_str + r"(.*?)\'",html,re.S)
    if len(result) == 0:
        print "Can't find image info"
        return None
    result = "http://hs.tgbus.com" + pattern_str + result[0]
    return result

def save_image(html,id):
    if html == None:
        return None
    path = r"/home/wubaolin/hs/images/" + str(id) + ".png"
    data = urllib.urlretrieve(html,path)
    print "Save succeed."

start_html = "hs.tgbus.com/db/a/"

for i in range(1,1500):
    the_html = start_html + str(i) + ".shtml"
    print 'fetching %d,%s'%(i,the_html)
    html = fetch_html(the_html)
    if html == None:
        print "Failed!"
        continue
    image = extract_image(html)
    save_image(image,i)

