using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SistemaGestionPersonas
{
    public partial class ventana1 : Form
    {
        public ventana1()
        {
            InitializeComponent();
        }

        public class Persona
        {
            protected string nombre;
            protected int edad;
            protected string genero;

            public Persona(string nombre, int edad, string genero)
            {
                this.nombre = nombre;
                this.edad = edad;
                this.genero = genero;
            }

            public virtual void mostrarInfo()
            {
                Console.WriteLine("Nombre: ", this.nombre);
                Console.WriteLine("Edad: ", this.edad);
                Console.WriteLine("Genero: ", this.genero);
            }
        }

        public class Empleado : Persona
        {
            protected double salario;
            protected string cargo;

            public Empleado(string nombre, int edad, string genero, double salario, string cargo) : base(nombre, edad, genero)
            {
                this.salario = salario;
                this.cargo = cargo;
            }

            public override void mostrarInfo()
            {
                base.mostrarInfo();
                Console.WriteLine("Cargo: ", this.cargo);
                Console.WriteLine("Salario: $", this.salario);
            }
        }

        public class Estudiante : Persona
        {
            private double nota;

            public Estudiante(string nombre, int edad, string genero, double nota) : base(nombre, edad, genero)
            {
                this.nota = nota;
            }

            public override void mostrarInfo()
            {
                base.mostrarInfo();
                Console.WriteLine("Nota: ", this.nota);
            }
        }

        public class Trabajador
        {
            Persona persona;
            string departamento;
            int horasTrabajadas;

            public Trabajador(Persona persona, string departamento, int horasTrabajadas)
            {
                this.persona = persona;
                this.departamento = departamento;
                this.horasTrabajadas = horasTrabajadas;
            }

            public double calcularSalario()
            {
                double tarifaPorHora = 10.0;
                if (departamento == "IT") tarifaPorHora *= 1.5;
                else if (departamento == "Gerencia") tarifaPorHora *= 2.0;
                return tarifaPorHora * horasTrabajadas;
            }

            public void mostrarInfo()
            {
                persona.mostrarInfo();
                Console.WriteLine("Departamento: ", this.departamento);
                Console.WriteLine("Horas trabajadas: ", this.horasTrabajadas);
                Console.WriteLine("Salario calculado: ", this.calcularSalario());
            }
        }

        public sealed class SistemaGestionPersonal
        {
            private static SistemaGestionPersonal instance = null;
            private static readonly object padlock = new object();

            private List<object> personal = new List<object>();

            private SistemaGestionPersonal()
            {
                // Constructor privado para evitar instanciación directa
            }

            public static SistemaGestionPersonal Instance
            {
                get
                {
                    lock (padlock)
                    {
                        if (instance == null)
                        {
                            instance = new SistemaGestionPersonal();
                        }
                        return instance;
                    }
                }
            }

            public void AgregarPersona(object persona)
            {
                personal.Add(persona);
            }

            public void MostrarTodoElPersonal()
            {
                foreach (var persona in personal)
                {
                    if (persona is Empleado empleado)
                    {
                        empleado.mostrarInfo();
                    }
                    else if (persona is Estudiante estudiante)
                    {
                        estudiante.mostrarInfo();
                    }
                    else if (persona is Trabajador trabajador)
                    {
                        trabajador.mostrarInfo();
                    }
                }
            }
        }
        private void btnSalir_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void btnAgregarEmpleado_Click(object sender, EventArgs e)
        {
            FormAddEmpleado agregarEmpleado = new FormAddEmpleado();
            agregarEmpleado.FormClosed += form2_closed;
            agregarEmpleado.Show();
            this.Hide();
        }
        private void form2_closed(object sender, FormClosedEventArgs e)
        {
            this.Show();
        }
        private void btnAgregarEstudiante_Click(object sender, EventArgs e)
        {
            FormAddEstudiante agregarEstudiante = new FormAddEstudiante();
            agregarEstudiante.FormClosed += form3_closed;
            agregarEstudiante.Show();
            this.Hide();
        }
        private void form3_closed(object sender, FormClosedEventArgs e)
        {
            this.Show();
        }
        private void btnAgregarTrabajador_Click(object sender, EventArgs e)
        {
            FormAddTrabajador agregarTrabajador = new FormAddTrabajador();
            agregarTrabajador.FormClosed += form4_closed;
            agregarTrabajador.Show();
            this.Hide();
        }
        private void form4_closed(object sender, FormClosedEventArgs e)
        {
            this.Show();
        }

        private void btnMostrarEmpleados_Click(object sender, EventArgs e)
        {
            FormMostrarTrabajadores verTrabajadores = new FormMostrarTrabajadores();
            verTrabajadores.FormClosed += form5_closed;
            verTrabajadores.Show();
            this.Hide();
        }
        private void form5_closed(object sender, FormClosedEventArgs e)
        {
            this.Show();
        }
    }
}
