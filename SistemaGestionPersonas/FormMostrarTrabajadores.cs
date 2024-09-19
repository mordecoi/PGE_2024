using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static SistemaGestionPersonas.ventana1;

namespace SistemaGestionPersonas
{
    public partial class FormMostrarTrabajadores : Form
    {
        public FormMostrarTrabajadores()
        {
            InitializeComponent();

            StringBuilder sb = new StringBuilder();
            Console.SetOut(new StringWriter(sb));

            SistemaGestionPersonal sistema = SistemaGestionPersonal.Instance;
            sistema.MostrarTodoElPersonal();
            Console.WriteLine("\n");

            string output = sb.ToString();

            Console.SetOut(Console.Out);

            textBox1.Text = output;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
