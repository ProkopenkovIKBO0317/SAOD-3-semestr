package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); // объявление потоковой переменной
	    double x = 0;                        // координата Х
	    double y = 0;                        // координата У
	    double a = 0;                        // сторона квадрата
	    double r = 0;                        // радиус круга

	// информирование пользователя о том, как работать с программой
	System.out.println("| The circle is inscribed in a center of foursquare.");
        System.out.println("| The area outside the circle is shaded.");
	System.out.println("| In begin you must enter length side foursquare and circle radius.");
        System.out.println("|==================================================================");

        // проверка типа полученных данных от пользователя
        try {
            System.out.print("Enter foursquare side length: ");
            a = sc.nextDouble();
            System.out.print("Enter circle radius: ");
            r = sc.nextDouble();

            if (a < 0 || r < 0) {
                System.out.println("Length side and radius MUST BE > 0!");
                System.exit(0);

            }

            double c = (a*a + a*a);
            if (Math.sqrt(c) <= r) {
                System.out.println("Circle is bigger than foursquare!");
                System.exit(0);

            }
            //Ввод кооридант точки
            System.out.print("Enter 'x' coordinate: ");
            x = sc.nextDouble();
            System.out.print("Enter 'y' coordinate: ");
            y = sc.nextDouble();

        } catch (Exception e) {
            System.out.println("Incorrect data entry! The programme will  be stopped.");
            System.exit(0);

        }

        // проверка условий, попадает ли точка в закрашенную область
        if ((x > r && y >= 0 && y < a && y > -a && x < a && x > -a) ||
                (x < -r && y <= 0 && y < a && y > -a && x < a && x > -a) ||
                (x < -r && y >= 0 && y < a && y > -a && x < a && x > -a) ||
                (x >= 0 && y > r && y < a && y > -a && x < a && x > -a) ||
                (x >= 0 && y < -r && y < a && y > -a && x < a && x > -a) ||
                (x <= 0 && y > r && y < a && y > -a && x < a && x > -a) ||
                (x <= 0 && y < -r && y < a && y > -a && x < a && x > -a)) {
            System.out.println("Yes. Your point falls into the shaded area.");
            System.exit(1);
        }
        else {
            System.out.println("No, sorry...");
            System.exit(0);

        }

    }
}
