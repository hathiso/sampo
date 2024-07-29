#include "Default_User_Widget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Interface/Stats_Character_Interface.h"

DEFINE_LOG_CATEGORY_STATIC(Wiget_Default,All,All);//VeryVerbose,Verbose,Log,Display,Warning,Error,Fatal
//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	IStats_Character_Interface* hp_value = Cast<IStats_Character_Interface>(GetOwningPlayerPawn());
	if (hp_value)
	{
		hp_value->get_hp_plaeyr().AddUObject(this, &ThisClass::Show_HP_Change);
	}
	else
		UE_LOG(Wiget_Default, Error, TEXT("Eroor Owning Player"));
	//image_skill_aa->SetVisibility(Header);
}
//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::Show_HP_Change(float on_hp_plaeyr, float on_max_hp_plaeyr)
{
	UE_LOG(Wiget_Default, Display,TEXT("on_hp_plaeyr = %f"), on_hp_plaeyr);
	UE_LOG(Wiget_Default, Display, TEXT("on_max_hp_plaeyr = %f"), on_max_hp_plaeyr);
	hp_text->SetText(FText::AsNumber(on_hp_plaeyr));
	hp_progress_bar->SetPercent((on_hp_plaeyr/(on_max_hp_plaeyr/100)/100));
}
//--------------------------------------------------------------------------------------------------