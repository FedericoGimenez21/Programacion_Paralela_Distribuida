/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class Simulation {
    
    public Simulation(int cantHilos,int cantI) {
        this.cantHilos = cantHilos;
        cantIter = cantI;
        hilos = new LinkedList();
        threadPool = Executors.newFixedThreadPool(cantHilos);
        iniciarProcesos();
    }
    
    public void iniciarProcesos(){
        Random rnd = new Random();
        for(int i = 0; i < cantHilos; i++)
            hilos.add(new SubProcess(rnd,cantIter/cantHilos)); //Lo que le tocara a cada hilo
    }
    
    public void iniciarTodos(){
        for(SubProcess s : hilos){
            threadPool.execute(s);
        }
        threadPool.shutdown();    
    }
    
    public double pi(){
        long start = System.currentTimeMillis();
        iniciarTodos();
        long totalDentro = 0;long totalTotal = 0;
        while (!threadPool.isTerminated());///Barrera
        for (SubProcess t : hilos) {
            totalDentro += t.getCantidadDentro();
            totalTotal += t.getCantidadTotal();
        }
        long end = System.currentTimeMillis();
        long elapsedTime = end - start;
        System.out.println(elapsedTime); 
        return 4.0 * totalDentro / totalTotal;
    }
      
    private int cantHilos = 0;
    private int cantIter = 0;
    private LinkedList<SubProcess> hilos;
    private ExecutorService threadPool;
}