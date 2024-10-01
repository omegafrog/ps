n = int(input())

hour = 0
minute = 0
second = 0

cnt = 0

while hour < n+1:
    if second ==60:
        minute+=1
        second = 0
    if minute == 60:
        hour+=1
        minute = 0
    
    if '3' in str(second) or '3' in str(minute) or '3' in str(hour):
       cnt+=1
       print(hour,":", minute,":", second)

    second+=1

print(cnt)