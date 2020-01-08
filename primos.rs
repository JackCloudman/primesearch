use std::time::{Instant};
use std::io;

fn buscar_primos(limite:u64){
    let mut listaprimos = vec![2];
    let mut i = 3;
    while i<=limite {
        let mut es_primo = true;
        let sqrt_limte = ((i as f64).sqrt()+1.0) as u64;
        for primo in &listaprimos{
            if i%*primo == 0 {
                es_primo = false;
                break;
            }
            if *primo>=sqrt_limte{
                break;
            }
        }
        if es_primo{
            listaprimos.append(&mut vec![i]);
        }
        i+=2;
    }
    //println!("{:?}",listaprimos); //Descomentar para imprimir los numeros
}
fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Error al leer el numero!");

    let trimmed = input.trim();
    let mut limite:u64 = 10;

    match trimmed.parse::<u64>() {
            Ok(i) => {limite = i},
            Err(..) => println!("Error al convertir el entero {}", trimmed),
    };
    println!("Limite: {}",limite);
    let start = Instant::now();
    buscar_primos(limite);
    let duration = start.elapsed();
    println!("El tiempo que tardo fue de: {:?}", duration);
}
