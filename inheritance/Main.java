package com.pjatk.inheritance;

public class Main {
    public static void main(String[] args) {

        System.out.println("Osoba:");
        Person person = new Person("Anna","Kowalska",1996,"kobieta");
        person.personInfo();
        System.out.println("======================\n");

        System.out.println("Student:");
        Student student = new Student("Mariusz","Nowak",1999,"mężczyzna","s11111");
        student.studentInfo();
        System.out.println("======================\n");

        System.out.println("Wykładowca:");
        Lecturer lecturer = new Lecturer("Malwina","Piotrowska",1987,"kobieta","Magister");
        lecturer.lecturerInfo();
        System.out.println("======================\n");

        System.out.println("Stypendysta:");
        Scholar scholar = new Scholar("Adam", "Mickiewicz", 2000, "mężczyzna", "s22111",1200.00);
        scholar.scholarInfo();
        System.out.println("======================\n");
    }
}
