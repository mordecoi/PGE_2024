   M S B A M L   `   `   `  ����N  JCalculadoraPropinas, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null9!clr-namespace:CalculadoraPropinasCalculadoraPropinas  5   	   $    CalculadoraPropinas.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   3local!clr-namespace:CalculadoraPropinas     5   	     � Title$  Propineitor��5   	   $	��450��6   $	��800��6*   .��5	      ��  �� Orientation$ Vertical=�6   .+�5
   
   �� $��Monto de la cuenta:��6   �� 5   
   -   5         ��Name$ txtBillAmount��5      $	��650��6)   �� 5   
   -   5         ��Name$ 	sliderPor��5      $	��650��6$    � Maximum$	 100Q�6V    � SmallChange$ 1Q�6d   �� 5   
   -   5         ��Name$ labpor��5      $�� ��6    $	��600��6+   �� 5   
   -   5         ��Name$ btnCalc��5      $��Calcular��6"   $	��100��65   $��50��6A   6M   �� 5   
   -   5        $ 
labPropina��5      $��La propina es: ��6$   $	��200��6>   �� 5   
   -   5        $ labTotal��5      $	��200��6"   5      5      