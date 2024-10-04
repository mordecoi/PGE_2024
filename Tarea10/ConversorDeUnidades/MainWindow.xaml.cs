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

namespace ConversorDeUnidades
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
        private readonly Dictionary<string, double> conversionesDistancia = new Dictionary<string, double>()
        {
            { "Kilometros", 1000 },  // 1 km = 1000 metros
            { "Metros", 1 },         // 1 m = 1 metro
            { "Centimetros", 0.01 },  // 1 cm = 0.01 metros
        };

        private readonly Dictionary<string, double> conversionesPeso = new Dictionary<string, double>()
        {
            { "Kilogramos", 1000 },  // 1 kg = 1000 gramos
            { "Gramos", 1 },         // 1 g = 1 gramo
            { "Centigramos", 0.01 },  // 1 cg = 0.01 gramos
        };

        // Método para convertir las unidades
        public double ConvertirUnidades()
        {
            double valorAConvertir = double.Parse(txtConvertir.Text);
            double valorConvertido = 0;

            // Obteniendo el texto de los ComboBox seleccionados
            string unidadA = (unidadesA.SelectedItem as ComboBoxItem).Content.ToString();
            string unidadB = (unidadesB.SelectedItem as ComboBoxItem).Content.ToString();

            if (conversionesDistancia.ContainsKey(unidadA) && conversionesDistancia.ContainsKey(unidadB))
            {
                // Conversión de distancias
                valorConvertido = valorAConvertir * (conversionesDistancia[unidadA] / conversionesDistancia[unidadB]);
            }
            else if (conversionesPeso.ContainsKey(unidadA) && conversionesPeso.ContainsKey(unidadB))
            {
                // Conversión de pesos
                valorConvertido = valorAConvertir * (conversionesPeso[unidadA] / conversionesPeso[unidadB]);
            }
            else
            {
                // Si no son compatibles, mostramos un mensaje de error
                MessageBox.Show("Por favor, seleccione unidades compatibles (ambas de distancia o ambas de peso).");
                return 0;
            }

            return valorConvertido;
        }


        // Evento del botón Convertir
        private void btnConvertir_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                double resultado = ConvertirUnidades();
                unidadConvertida.Content = resultado.ToString("N8");
            }
            catch (NullReferenceException)
            {
                MessageBox.Show("Por favor, elija ambas opciones.");
            }
            catch (FormatException)
            {
                MessageBox.Show("Por favor, ingrese un valor válido para convertir.");
            }
        }
    }
}
