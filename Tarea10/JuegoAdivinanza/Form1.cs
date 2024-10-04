using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JuegoAdivinanza
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            numero = num_ran.Next(0, 100);
        }
        Random num_ran = new Random();
        public int numero = 0;

        private void verificar_numero()
        {
            string pista_text = string.Empty;
            if (int.Parse(tbox_intento.Text) < numero)
                pista_text = "\nEl numero es mayor.";
            else
                pista_text = "\nEl numero es menor.";

            double comp = numero%2;
            if (comp == 0)
                pista_text += "\nEl numero es par.";
            else
                pista_text += "\nEl numero es impar.";

            lab_pista.Text = pista_text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (int.Parse(tbox_intento.Text) == numero)
            {
                MessageBox.Show("Adivinaste el numero ¡Felicidades!");
                numero = num_ran.Next(0, 100);
                lab_pista.Text = string.Empty;
                lab_numeros.Text = "Numeros usados: ";
            }
            else
            {
                verificar_numero();
                if (lab_numeros.Text.Contains(tbox_intento.Text) == false)
                    lab_numeros.Text = lab_numeros.Text + tbox_intento.Text + " | ";
            }
        }
    }
}
