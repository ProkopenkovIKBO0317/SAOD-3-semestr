package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 0;
        int m = 0;
        int index = 0;
        int pos;
        int check = 0;

        // Ввод столбцов и строк матрицы с проверкой условий
        System.out.print("Введите число строк (1 < n <= 100): ");
        try {
        while (check == 0) {
            n = sc.nextInt();
            if (n > 1 && n <= 100) {
                check++;
            }
            else {
                System.out.print("Введенное значение не соответсвует условию! Повторите ввод: ");
            }
        }
        System.out.println();
        check = 0;

        System.out.print("Введите число столбцов (1 < m <= 50): ");
        while (check == 0) {
            m = sc.nextInt();
            if (m > 1 && m <= 50) {
                check++;
            }
            else {
                System.out.print("Введенное значение не соответствует условию! Повторите ввод: ");
            }
        }

        } catch (Exception e) {
            System.out.println("Ошибка ввода данных! Работа программы будет завершена.");
            System.exit(0);

        }

        // Создание двумерного массива
        try {
            int[][] arr = new int[n][m];

            // Инициализация матрицы
            System.out.println("Введите матрицу");
            for (int i = 0; i < n; i++) {
                System.out.println("Строка " + (i+1));
                for (int j = 0; j < m; j++) {
                    System.out.println("Элемент " + (j+1));
                    arr[i][j] = sc.nextInt();
                }
                index = i;
            }
            if ((index + 1) > arr.length) {
                System.out.println("Выход за пределы массива! Остановка программы.");
                System.exit(0);
            }
            System.out.println("Исходная матрица");
            showMatrix(arr,n,m);

            // Осуществление циклического сдвига влево
            System.out.println("Введите число k");
            pos = sc.nextInt();
            System.out.println("k = " + pos);
            shiftLeft(arr, pos);
            System.out.println();
            System.out.println("Матрица после сдвига");
            showMatrix(arr,n,m);
        } catch (Exception e) {
            System.out.println("Ошибка! Ошибка! Перезапустите программу.");
            System.exit(0);
        }
    }

    // Описание функции, осуществляющей сдвиг матрицы слево по столбцам
    public static void shiftLeft(int arr[][], int pos) {
        for (int i = 0; i < arr.length; i++) {
            int realPos = pos % arr[i].length;
            if (realPos == 0)
                continue;
            int rowLength = arr[i].length;
            int[] temp = new int[rowLength];
            for (int j = 0; j < rowLength; j++) {
                int newIndex = (j-realPos < 0) ? rowLength + j - realPos : j - realPos;
                temp[newIndex] = arr[i][j];
            }
            for (int j = 0; j < rowLength; j++) {
                arr[i][j] = temp[j];
            }
        }
    }

    public static void showMatrix(int arr[][], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    }
}
