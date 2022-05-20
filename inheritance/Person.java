package com.pjatk.inheritance;

public class Person {
    protected String name;
    protected String surname;
    protected int yearOfBirth;
    protected String gender;

    public Person(String name, String surname, int yearOfBirth, String gender){
        this.name=name;
        this.surname=surname;
        this.yearOfBirth=yearOfBirth;
        this.gender=gender;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public int getYearOfBirth() {
        return yearOfBirth;
    }

    public String getGender() {
        return gender;
    }

    public void personInfo(){
        System.out.println("Imie: "+name);
        System.out.println("Nazwisko: "+surname);
        System.out.println("Rok urodzenia: "+yearOfBirth);
        System.out.println("Płeć: "+gender);
    }
}
