
# -*-coding: UTF-8 -*-
import numpy as np
import math
import string
from scipy import interpolate
import self_optimization as mf


M = 3
N = 50

MaxPRB = N * 0.40
W = 28
K = 28
RSRP0 = -105   # dBm
sigma = 0.95
Locations = [[10, 4, 1.5],
             [22, 4, 1.5],
             [18, 20, 1.5]]

Pt0 = 10 * np.ones((M, 1))
Pt_max = 20
Pt = np.zeros((M, 1))

RS_Sch = 0 * np.ones((M, 1), int)   # PA = -6dB

RS_Pt = np.zeros((M, 1))

for m in range(M):
    Pt[m, 0] = Pt_max
    RS_Pt[m, 0] = mf.RS_PDSCH_allocation(Pt[m, 0], N, RS_Sch[m, 0])

[RSRPn, Cover_rate] = mf.Coverage_rate(RS_Pt, Locations, M, RSRP0, W, K)

# 假设上报的SINR为M*N维度 或CQI
SINR = 10*np.random.rand(M, N)
S = SINR.copy()    # 进行备份

P_Sch = np.zeros((M, 1))
RS_Sch = np.zeros((M, 1))

A1 = np.zeros((M, N))
PRB_Count = np.zeros((M, 1))
P_Binary = np.zeros((M, 5))

for j in range(N):
    SINR_Temp = SINR[:, j]  # 某一列
    Idx = SINR_Temp.tolist().index(max(SINR_Temp))
    if PRB_Count[Idx] < MaxPRB:
        PRB_Count[Idx] = PRB_Count[Idx] + 1
        A1[Idx][j] = 1
    else:
        SINR[Idx][j] = 0
        SINR_Temp = SINR[0: M, j]
        Idx = SINR_Temp.tolist().index(max(SINR_Temp))
        if PRB_Count[Idx] < MaxPRB:
            PRB_Count[Idx] = PRB_Count[Idx] + 1
            A1[Idx][j] = 1
        elif PRB_Count[Idx] >= MaxPRB:
            SINR[Idx][j] = 0
            SINR_Temp = SINR[0: M, j]
            Idx = SINR_Temp.tolist().index(max(SINR_Temp))
        else:
            PRB_Count[Idx] = PRB_Count[Idx] + 1
            A1[Idx][j] = 1

for m in range(M):
    P_Binary[m, :] = [0, 1, 0, 0, 0]

S0 = np.hstack((A1, P_Binary))        # S0 = [A1, P_Binary]

print(S0)
print(Cover_rate)    # 当前的覆盖率等于1,float型
print(type(Cover_rate))
P_W = np.power(10 * np.ones((M, 1)), (Pt / 10 - 3 * np.ones((M, 1))))  # dBm转化为w
EE0 = np.sum(np.sum(np.multiply(A1, S))) / np.sum(P_W)

np.savetxt("/home/noone/temp_conf.txt",RSRPn)
print(EE0)   # 输出计算的能效,numpy.float型
print(type(EE0))
S0_list = S0.tolist()
print(S0_list)
print(type(S0_list))

str_S = []
for i in S0_list:
    for j in i:
        str_S.append(str(int(j)))
send_conf = []
S0_str = ",".join(str_S)
send_conf.append(S0_str)
send_conf.append(str(Cover_rate))
send_conf.append(str(EE0))
print(send_conf)
with open("/home/noone/temp_conf.txt","a") as f:
    f.write(",".join(send_conf))















