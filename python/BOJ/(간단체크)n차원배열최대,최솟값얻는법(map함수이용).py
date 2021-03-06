vertices = [
    [1, 7, 12], 
    [4, 7, 13],
    [1, 5, 17], 
    [3, 5, 20], 
    [2, 4, 24], 
    [1, 4, 28], 
    [3, 6, 37], 
    [5, 6, 45], 
    [2, 5, 62], 
    [1, 2, 67], 
    [5, 7, 73]]



three_d = [
    [
        [1, 7, 12], 
        [4, 7, 13]
    ],
    [
        [1, 5, 17], 
        [3, 5, 20], 
    ],
    [
        [2, 4, 24], 
        [1, 4, 28], 
    ],
    [
        [3, 6, 37], 
        [5, 6, 45],
    ],
    [
        [2, 5, 62], 
        [1, 2, 67], 
    ]
]


four_d = [
[
    [
        [1, 7, 12], 
        [4, 7, 13]
    ],
    [
        [1, 5, 17], 
        [3, 5, 20], 
    ],
    [
        [2, 4, 24], 
        [1, 4, 28], 
    ]
],
[
    [
        [3, 6, 37], 
        [5, 6, 45],
    ],
    [
        [2, 5, 62], 
        [1, 2, 67], 
    ],
    [
        [200, 500, 6200], 
        [100, 200, 6700], 
    ]
]
]
print(max(map(max,vertices)))
print(max([max(map(max,two_d)) for two_d in three_d])) 
print(max(max([max(map(max,two_d)) for two_d in three_d]) for three_d in four_d))
# 3차원 이상부터는 리스트 컴프리헨션쓰기(근데 그럼 max함수의 메리트가 사라지는듯)