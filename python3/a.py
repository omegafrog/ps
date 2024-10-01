def calculate_production_time_and_cost(transfer_rate, diameter, length):
    # 가공조건 입력
    transfer_rate = transfer_rate  # 이송 속도 (mm/min)
    diameter = diameter  # 지름 (mm)
    length = length  # 길이 (mm)

    # 공구조건 입력
    t = 60  # 초경공구 (sec)
    n = 0.25  # 속도계수
    v = 4.064  # 절삭속도 (m/s)

    # 공작기계조건 입력
    initial_cost = 10800  # 초기구입비용 ($)
    resharpening_cost = 2  # 재연삭비 ($)
    tool_cost = 6  # 공구구입비 ($)
    tool_change_time = 300  # 공구교체와 재맞춤 시간 (sec)

    # 비용 입력
    worker_wage = 0.0015  # 작업자 임금 ($/sec)
    indirect_cost = 1  # 작업자 및 기계의 간접비 (%)
    non_production_time = 120  # 비생산시간 (sec)

    # 최저 생산시간을 위한 절삭속도 계산
    min_time_speed = (length / 1000) / (transfer_rate / 60)  # 최저 생산시간을 위한 절삭속도 (m/s)

    # 최소 생산비용을 위한 절삭속도 계산
    min_cost_speed = v * (1 + (resharpening_cost + tool_cost) / (initial_cost + tool_cost))  # 최소 생산비용을 위한 절삭속도 (m/s)

    # 최저 생산시간과 최소 생산비용 계산
    min_time = (length / 1000) / min_time_speed  # 최저 생산시간 (sec)
    min_cost = (initial_cost + resharpening_cost + tool_cost) / v + tool_change_time  # 최소 생산비용 ($)

    # 입력값 변화에 따른 생산시간과 생산비의 변화율 계산
    production_time_change = ((length / 1000) / (transfer_rate / 60) - min_time_speed) / min_time_speed * 100  # 생산시간 변화율 (%)
    production_cost_change = ((v * (1 + (resharpening_cost + tool_cost) / (initial_cost + tool_cost))) - v) / v * 100  # 생산비 변화율 (%)

    return production_time_change, production_cost_change

# 입력값 설정
transfer_rate = 0.25  # 이송 속도 (mm/min)
diameter = 76  # 지름 (mm)
length = 300
[production_time_change,production_cost_change] = calculate_production_time_and_cost(transfer_rate, diameter, length)
print(production_cost_change)
print(production_time_change)