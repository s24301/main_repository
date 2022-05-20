package com.edu.pjatk.model;

import java.util.Scanner;

public class Customer {
    private String name;
    private TypeOfCustomer type;
    private String address;
    private String nip;

    public Customer(){
    }

    public Customer(String name, TypeOfCustomer type, String address){
        this.name = name;
        this.type = type;
        this.address = address;

        Scanner input = new Scanner(System.in);

        if (type == TypeOfCustomer.COMPANY){
            System.out.printf("Enter NIP: ");
            nip = input.next();
        }else {
            nip = "-";
        }

    }

    public void customerInfo(){
        System.out.println("CUSTOMER:");
        System.out.println("Name: "+name);
        System.out.println("Address: "+address);
        System.out.println("NIP: "+nip);
        System.out.println("-----------------");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public TypeOfCustomer getType() {
        return type;
    }

    public void setType(TypeOfCustomer type) {
        this.type = type;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getAddress() {
        return address;
    }

    public String getNip() {
        return nip;
    }

    public void setNip(String nip) {
        this.nip = nip;
    }
}
