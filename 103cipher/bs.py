##
## EPITECH PROJECT, 2023
## 103cipher
## File description:
## bs
##

from math import *
import sys

# ex1
def str2matrix(s):
    matrix = []
    row = []
    for c in s:
        asc_val = ord(c)
        row.append(asc_val)
    matrix.append(row)
    return matrix

# ex2
def create_mat_n(str, num):
    matrix = []
    row = []
    for c in str:
        row.append(ord(c))
        if len(row) == int(num):
            matrix.append(row)
            row = []
    if row:
        matrix.append(row)
    return matrix

# ex3
def multiply_matrices(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        raise ValueError("Number of columns in the first matrix must be equal to the number of rows in the second matrix")
    matrix = []
    for i in range(len(mat1)):
        matrix.append([0] * len(mat2[0]))
    for i in range(len(mat1)):
        for j in range(len(mat2[0])):
            for k in range(len(mat2)):
                matrix[i][j] += mat1[i][k] * mat2[k][j]
    return matrix

# ex4
def transpose_matrix(matrix):
    transposed_matrix = list(map(list, zip(*matrix)))
    return transposed_matrix

# ex5
def det_mat2x2(matrix):
    det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0])
    return det

# ex6
def inverse_2x2(matrix):
    if len(matrix) != 3 or len(matrix[0]) != 2 or len(matrix[1]) != 2:
        raise ValueError("Input matrix must be a 2x2 matrix")
    a, b, c, d = matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]
    det = a * d - b * c

    if det == 0:
        raise ValueError("Matrix is not invertible")
    inverse = [[d / det, -b / det], [-c / det, a / det]]
    return inverse

# ex7
def cofactor(matrix, i, j):
    if not (0 <= i < 3) or not (0 <= j < 3):
        raise ValueError("Indices i and j must be in the range [0, 2]")

    minor_matrix = [row[:j] + row[j+1:] for row in (matrix[:i] + matrix[i+1:])]

    sign = (-1) ** (i + j)
    cofactor_value = sign * det_mat2x2(minor_matrix)

    return cofactor_value

# ex8
def det_mat3x3(matrix):
    return (
        matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
        matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
        matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0])
    )

# ex9
def adjugate_matrix(matrix):
    n = len(matrix)
    adjugate = [[cofactor(matrix, i, j) for j in range(n)] for i in range(n)]
    adjugate_transposed = [list(row) for row in zip(*adjugate)]  # Transpose without using NumPy
    return adjugate_transposed

def inverse_matrix(matrix):
    if det_mat3x3(matrix) == 0:
        raise ValueError("Cannot invert the matrix.")

    det_inv = 1 / det_mat3x3(matrix)
    adjugate = adjugate_matrix(matrix)

    inv = [[det_inv * adjugate[i][j] for j in range(len(adjugate[0]))] for i in range(len(adjugate))]
    return inv

# matrix_3x3 = [[2, 3, 4], [5, 12, 7], [8, 9, 10]]

# print("Original Matrix:")
# for row in matrix_3x3:
#     print(row)

# try:
#     inverse_result = inverse_matrix(matrix_3x3)
#     print("\nInverse Matrix:")
#     for row in inverse_result:
#         print(row)
# except ValueError as e:
#     print("\nError:", e)
print(create_mat_n("Homer S", 3))