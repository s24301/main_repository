package com.edu.pjatk.model;

import java.time.LocalDate;

public class Main {
    public static void main(String[] args){
        Product product = new Product("ABC123","TV",1000);

        System.out.println("Code: "+product.getCode());
        System.out.println("Name: "+product.getName());
        System.out.println("Price: "+product.getPrice());

        InvoicePosition position = new InvoicePosition(product,3);

        System.out.println(position.getNettoPrice());
        System.out.println(position.getGrossPrice());
        System.out.println(position.getTaxValue());
        System.out.println("--------------------------------------------");

        Customer customer1 = new Customer("Peter",TypeOfCustomer.COMPANY,"Warsaw, POLAND");

        Invoice invoice = new Invoice(LocalDate.of(2022,03,30),LocalDate.of(2022,04,04),customer1);
        invoice.addPosition(new Product("ABC123","TV",1000));
        invoice.addPosition(new Product("ABC123","TV",1000));
        invoice.addPosition(new Product("CBA321","Radio",500));
        invoice.addPosition(new Product("ABC123","TV",1000));
        invoice.addPosition(new Product("CBA321","Radio",500));
        invoice.setTotal();
        printoutInvoice(invoice);


    }

    private static void printoutInvoice(Invoice invoice){
        System.out.println("|NAZWA\t|ILOSC\t|CENA NETTO\t|CENA BRUTTO\t|STAWKA VAT\t|PODATEK");
        System.out.println("**********************************************************************");
        for(InvoicePosition p : invoice.getPositions()){
            System.out.print("|"+p.getProduct().getName()+"\t|");
            System.out.print(p.getCount()+"\t|");
            System.out.print(p.getNettoPrice()+"\t\t|");
            System.out.print(p.getGrossPrice()+"\t\t|");
            System.out.print(p.getTax()+"\t\t|");
            System.out.println(p.getTaxValue());
            System.out.println("--------------------------------------------");
        }
        invoice.getCustomer().customerInfo();
        System.out.println("Date: "+invoice.getDate());
        System.out.println("Due to: "+invoice.getDeadline());
        System.out.println("TOTAL: "+invoice.getTotal());
    }
}

