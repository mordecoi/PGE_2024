using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CalculadoraPropinas
{
    /// <summary>
    /// Lógica de interacción para MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void sliderPor_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            labpor.Content = ((int)sliderPor.Value);
        }

        private void btnCalc_Click(object sender, RoutedEventArgs e)
        {
            double cuenta = 0;
            double propina = 0;
            double total = 0;

            try
            {
                cuenta = double.Parse(txtBillAmount.Text);
                if (cuenta <= 0)
                {
                    MessageBox.Show("El valor de la cuenta debe ser positivo.");
                    return;
                }

                double porcentaje = sliderPor.Value / 100; // Convertir el porcentaje a decimal
                propina = cuenta * porcentaje;
                total = cuenta + propina;

                labPropina.Content = $"La propina es: {propina:C3}";
                // Usando interpolación de cadenas para un formato más claro
                labTotal.Content = $"El total a pagar es: {total:C3}";
            }
            catch (FormatException)
            {
                MessageBox.Show("Por favor, ingrese un valor numérico válido para la cuenta.");
            }
        }
    }
}
