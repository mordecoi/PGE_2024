using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Prueba1PGE
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            button1.Text = "Hola Mundo";
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            button1.ForeColor = Color.Green;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            button1.Width = button1.Width + 10;
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            button1.Height = button1.Height + 10;
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            button1.BackColor = Color.Red;
        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            button1.Enabled = false;
        }
    }
}
