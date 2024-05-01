import java.util.ArrayList;

import org.junit.internal.Throwables;

public class Main {

  ArrayList<Robot> robots;
  ArrayList<Componente> nombreComponente;

  public Main() {
      robots = new ArrayList < > ();
      nombreComponente = new ArrayList < > ();
  }

  //Metodo que busca robot segun su codigo
  public Robot buscarRobots(String codigo){
    for (Robot robot : robots) {
      if (robot.getCodigo().equals(codigo)) {
        return robot;
      }
    }
    return null;
  }

  //Metodo que recibe por parametro la info de un robot y lo agrega a la lista de robots. con execpcion si ya existe el robot con el codigo ingresado para creacion
  public void agregarRobot(Robot robot) throws Exception {
    if(buscarRobots(robot.getCodigo()) != null){
      throw new Exception("El robot ya existe");
    }
    robots.add(robot);
  }

//Metodo que recibe info del robot y agrega el componente al robot 
  public void agregarComponente(Componente componente, String codigo) throws Exception{
    Robot robot = buscarRobots(String codigo);
    if(robot == null){
      throw new Exception("El robot no encontrado");
    }
    robot.agregarComponente(componente);
    componenteNombre.add(componente);
  }

//Metodo que elimina un robot dado su codigo y agrege un componente al robot
  public void eliminarRobot(String codigo) throws Exception{
      Robot roboteliminar = null;
      for (Robot robot : robots){
        if (robot.getCodigo().equals(codigo)){
          roboteliminar = robot;
          break;
        }
      }
    if (roboteliminar == null){
      throw new Exception("El robot no existe");
    }
    Robot.eliminar(roboteliminar);
  }
  
//Metodo que retorna una lista con los nombres 
  Public List <String> listarComponentes(){
    return new ArrayList<>(componenteNombre);
  }
  
}