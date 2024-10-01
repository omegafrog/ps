import shutil
str = "https://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-roberto-nickson-5PQn41LFsQk-unsplash-15a5966e-a967-4162-bbc0-da320a589037.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-a7b8dc30-c517-42cc-9334-6193f1a06c84.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-074bb6eb-0575-4cfa-8c09-95df679e9713.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-aa30b2f1-365f-41fa-88c1-ed54f10e54d4.png,https://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-roberto-nickson-5PQn41LFsQk-unsplash-407368ee-04cc-465a-a96f-23e89098742d.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-5e9f1660-88aa-4a09-80f6-ae7ed7e31f0f.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-7c0e4b7c-9c2f-449c-88ab-620f63c102a0.png,https://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-2ad89a90-6e08-4cbb-b456-a55f0ea99cc6.png,htt...\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-7936d5e3-c354-4686-b853-670e5f96ebac.png,sheet-roberto-nickson-5PQn41LFsQk-unsplash-6baa3113-ff39-4a32-a71c-12ac15598fee.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-7fa27fea-0736-4b8d-8fba-f967f2f80afa.png,https://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-4003748e-dc0a-4af9-b493-4e9c294c88ba.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-f88bc453-4337-4d83-b8b1-c18a0380878f.png,https://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-1276c27f-4f8b-49e6-95fc-0ea37126fc22.png,htt...\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-20f07aaf-71d8-40e7-905e-5be183b9cd89.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-47770a56-85e1-4910-a89f-4434281c4e9b.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-b82eabcc-d5d1-4d2e-81a6-2245e59a26da.png,sheet-drew-hays-NR-c8f1543c-8acd-4840-9adc-4ddf22a358f1.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-8d862dce-a1f5-4cbc-948c-8fd361d4150c.png,sheet-drew-hays-NR-23b3c069-3215-413e-8763-280a1bdde5ae.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-roberto-nickson-5PQn41LFsQk-unsplash-36ab570c-1151-4750-b71d-9005e55650e4.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-2c3b42b1-115c-4722-9503-29745da1df18.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-385b9476-0e30-41a3-ac16-4962dc61927a.png,https://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-roberto-nickson-5PQn41LFsQk-unsplash-5aa62cc0-add1-4978-9521-05c88861f91c.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-5c508073-1905-4503-aa26-0e3830732851.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-roberto-nickson-5PQn41LFsQk-unsplash-cc891166-306f-4aa8-ac89-1a6624154aa8.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-06d1bfd3-8500-4d57-a94e-807cdc0fa3ac.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-antonis-chalas-kbRaQrXWeIM-unsplash-e7a67815-7d0b-44fa-bb2e-ca3f5c0a8aa2.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-2405640a-8523-4a00-a0f7-b9f3286f68e6.png,\nhttps://mypianobucket.s3.ap-northeast-2.amazonaws.com/sheet-drew-hays-NR-84728681-899c-4fa3-b529-ff51de84606a.png,\n"

sheets = str.split("\n")

data = []
for sheet in sheets:
    sheetUrls = sheet.split(",")
    sheetUrls = sheetUrls[:-1]
    data.append(sheetUrls)

fromFilePath = "/mnt/c/Users/jiwoo/Downloads/dummy.pdf"

for sheets in data:
    for sheet in sheets:
        toFileName = sheet.split("/")[-1]
        toFileNameNotExtension = toFileName.split(".")[:-1]

        shutil.copyfile(fromFilePath, "/mnt/c/Users/jiwoo/Downloads/changedsheets/"+toFileNameNotExtension[0]+".pdf")
        print(fromFilePath, toFileName)





