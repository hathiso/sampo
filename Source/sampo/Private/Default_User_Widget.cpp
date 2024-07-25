#include "Default_User_Widget.h"
#include "Interface/Stats_Character_Interface.h"

//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	//IStats_Character_Interface* hp_value = Cast<IStats_Character_Interface>(GetOwningPlayerPawn());
	//if (hp_value)
	//{
	//	hp_value->get_hp_plaeyr().AddDynamic(this, &ThisClass::Show_HP_Change);
	//}
}
//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::Show_HP_Change() 
{

}
//--------------------------------------------------------------------------------------------------
