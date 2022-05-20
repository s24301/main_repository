package com.edu.pjatk.model;

import java.time.LocalDate;
import java.util.ArrayList;

public class Invoice {
    private ArrayList<InvoicePosition> positions = new ArrayList<InvoicePosition>();
    LocalDate date;
    LocalDate deadline;
    double total;
    Customer customer;

    public Invoice(){}

    public Invoice(LocalDate date, LocalDate deadline, Customer customer){
        this.date=date;
        this.deadline=deadline;
        this.customer=customer;

        setTotal();
    }

    public void setTotal(){
        double sum=0;
        for (InvoicePosition position : positions){
            sum=sum+position.getGrossPrice();
        }
        this.total = sum;
    }

    public Customer getCustomer() {
        return customer;
    }

    public LocalDate getDate(){
        return date;
    }

    public LocalDate getDeadline() {
        return deadline;
    }

    public double getTotal() {
        return total;
    }

    public ArrayList<InvoicePosition> getPositions() {
        return positions;
    }

    public void addPosition(InvoicePosition position) {
        positions.add(position);
    }

    public void addPosition(Product product) {
        InvoicePosition position = positionWithProduct(product);
        if (position==null){
            addPosition(new InvoicePosition(product));
            return;
        }
        position.setCount(position.getCount()+1);
    }

    private InvoicePosition positionWithProduct(Product product){
        for (InvoicePosition position : positions){
            if (position.getProduct().getCode().equals(product.getCode()))
                return position;
        }
        return null;
    }

}
