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

namespace Conversor_de_divisas
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

        private int opcion1 = 0;
        private int opcion2 = 0;
        private double convertirDivisa(double valor, int divisa1, int divisa2)
        {
            double divisaConvertida = 0.0;
            double[] divisas = {1.0, 0.89, 962.5 };

            divisaConvertida = (valor * divisas[divisa2]) / divisas[divisa1];

            return divisaConvertida;
        }
        private void btnConvertir_Click(object sender, RoutedEventArgs e)
        {
            txtCantidad.Text = convertirDivisa(double.Parse(txtCantidadTransformada.Text), opcion1, opcion2).ToString();
        }
        private void USD_Click(object sender, RoutedEventArgs e)
        {
            opcion1 = 0;
        }
        private void ARS_Click(object sender, RoutedEventArgs e)
        {
            opcion1 = 2;
        }
        private void EUR_Click(object sender, RoutedEventArgs e)
        {
            opcion1 = 1;
        }
        private void USD2_Click(object sender, RoutedEventArgs e)
        {
            opcion2 = 0;
        }
        private void ARS2_Click(object sender, RoutedEventArgs e)
        {
            opcion2 = 2;
        }
        private void EUR2_Click(object sender, RoutedEventArgs e)
        {
            opcion2 = 1;
        }
    }
}
