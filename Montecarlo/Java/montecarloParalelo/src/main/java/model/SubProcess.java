/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

import java.util.Random;


public class SubProcess extends Thread {

    public SubProcess(Random gen,long ct) {
        generador = gen;
        cantidadTotal = ct;
    }
    
    
    private double distancia(double x,double y){
        return Math.sqrt(x*x+y*y);
    }
    
    public long getCantidadDentro() {
        return cantidadDentro;
    }

    public void setCantidadDentro(long cantidadDentro) {
        this.cantidadDentro = cantidadDentro;
    }

    public long getCantidadTotal() {
        return cantidadTotal;
    }
    
    @Override
    public void run() {
        for (long i = 0; i < cantidadTotal; i++) {
            double x = generador.nextDouble();
            double y = generador.nextDouble();
            if (distancia(x, y) <= 1) {
                cantidadDentro++;
            }
        }
    }
    
    private long cantidadDentro = 0;
    private long cantidadTotal = 0;
    private Random generador = null;
}