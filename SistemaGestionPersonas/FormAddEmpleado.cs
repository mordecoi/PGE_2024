using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static SistemaGestionPersonas.ventana1;

namespace SistemaGestionPersonas
{
    public partial class FormAddEmpleado : Form
    {
        public FormAddEmpleado()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SistemaGestionPersonal sistema = SistemaGestionPersonal.Instance;

            // Agregar una persona
            Empleado nuevoEmpleado = new Empleado(textBox1.Text, int.Parse(textBox2.Text), textBox3.Text, double.Parse(textBox4.Text), textBox5.Text);
            sistema.AgregarPersona(nuevoEmpleado);

            this.Close();
        }

        private void textBox1_MouseClick(object sender, MouseEventArgs e)
        {
            textBox1.Clear();
        }

        private void textBox2_MouseClick(object sender, MouseEventArgs e)
        {
            textBox2.Clear();
        }

        private void textBox3_MouseClick(object sender, MouseEventArgs e)
        {
            textBox3.Clear();
        }

        private void textBox4_MouseClick(object sender, MouseEventArgs e)
        {
            textBox4.Clear();
        }
        private void textBox5_MouseClick(object sender, MouseEventArgs e)
        {
            textBox5.Clear();
        }
    }
}
