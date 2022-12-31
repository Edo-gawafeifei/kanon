#include<stdio.h>
char get_choice(void);
char get_first(void);
void zhaozhishu(void);
void jisuandianfei(void);
void suanxingzuo(void);
char b(void);
void zhengxushuchu(void);

#define RATE1 0.13230//首次使用360kwh的费率
#define RATE2 0.15040//接着再使用108kwh的费率
#define RATE3 0.30025//接着再使用252kwh的费率
#define RATE4 0.34025//使用超过720kwh的费率
#define BREAK1 360.0//费率的第一个分界点
#define BREAK2 468.0//费率的第二个分界点
#define BREAK3 720.0//费率的第三个分界点
#define BASE1 (RATE1*BREAK1)//使用360kwh的费用
#define BASE2 (BASE1+(RATE2*(BREAK2-BREAK1)))//使用 468kwh的费用
#define BASE3 (BASE2+(RATE3*(BREAK3-BREAK2)))//使用720kwh的费用

int main(void)
{
	char choice;
	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a':jisuandianfei();
			break;
		case 'b':suanxingzuo();
			break;
		case 'c':zhengxushuchu();
			break;
		case 'd':zhaozhishu();
			break;
		default:printf("输入错误！\n");
			break;
		}
	}
	printf("欢迎您的再次使用！！");
}
char get_choice(void)
{
	int ch;
	printf("请输入您的选择：\n");
	printf("a.计算电费                   b.计算星座\n");
	printf("c.正序输出                   d.找范围内质数\n");
	printf("q.结束程序\n");
	ch = get_first();
	while ((ch<'a' || ch>'d') && ch != 'q')
	{
		printf("请重新输入一个字母，在a,b,c,d,或者q.\n");
		ch = get_first();
		printf("哎呀呀!人家不小心看错了嘛，麻烦你又输入一遍了~~\n");
	}
	return ch;
}

char get_first(void)
{
	int ch;
	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}
void zhaozhishu(void)
{
	int i, j, k, a, b, min, max;
	printf("***********************************************************\n");
	printf("*                                                         *\n");
	printf("*                  欢迎您使用找范围质数程序               *\n");
	printf("*                                                         *\n");
	printf("***********************************************************\n");
	printf("请您输入两个正数：\n");
	scanf_s("%d %d", &a, &b);
	min = (a < b) ? a : b;
	max = (a < b) ? b : a;
	for (i = min; i <= max; i++){
		for (j = 2, k = 1; j < i; j++){
			if (i%j == 0)
				k = 0;
		}
		if (k == 1)
			printf("%d    ", j);
	}
}
void jisuandianfei(void)
{
	double kwh;//使用的度数 
	double bill;//电费
	
	printf("*********************************************************\n");
	printf("*                                                       *\n");
	printf("*                  欢迎您使用计算电费程序               *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
	printf("请输入您使用的度数：\n");
	printf("请输入一个正数：\n");
	
	scanf_s("%lf", &kwh);

	if (kwh <= BREAK1)
		bill = RATE1*kwh;//368--468kwh
	else if (kwh <= BREAK2)
		bill = BASE1 + (RATE2*(kwh - BREAK1));
	else if (kwh <= BREAK3)
		bill = BASE2 + (RATE3*(kwh - BREAK2));
	else
		bill = BASE3 + (RATE4*(kwh - BREAK3));
	printf("%.1lf度的费用为%1.2lf元。\n", kwh, bill);
}
void suanxingzuo(void)
{
	char a;

	a = b();

	switch (a)
	{
	case 'a':printf("你的星座是白羊座\n");
		printf("用一句话来概括就是脾气火爆的热血达人，他们直率、\n坦诚、慷慨、冲动、大大咧咧，对于自己既定的目标，\n完成是唯一的选择，\
			   			白羊们不给自己其他的选择，\n有很强的决心和毅力。他们通常都富有决断力，\n不会婆婆妈妈，不注重细节，没有耐心.\n");
		break;

	case 'b':printf("你的星座是金牛座\n");
		printf("保守型性格，他们慢热，不会急躁鲁莽，只会稳健地进取，不喜欢变动，比较固执，一旦认定一件事，真的是连十头牛都拉不回来呢，\
			   			同时他们也是务实的，对于物质世界的美好例如金钱和美食有追求。金牛座的人需要稳定、持久的关系，他们不会轻易放弃一段感情，\
									.对他们来说，喜欢就是喜欢，不喜欢就是不喜欢，不能勉强。");
		break;

	case 'c':printf("你的星座是双子座\n");
		printf("聪明敏锐，又能言善辩，能让男女之间相处和谐，并营造出快乐的氛围，但是双子们对爱往往缺乏向上心，在有结果后，便会立刻有\
			   			   厌倦感出现。并将恋情所带来的痛苦，转变为发展下一段恋情时最好的借口。");
		break;

	case 'd':printf("你的星座是巨蟹座\n");
		printf("温和、真诚，比较敏感，而且缺乏安全感，自我保护意识强烈，所以本人也很慢热，也说明为人重感情，朋友一旦选择了，他们希望是\
			   			一生的。巨蟹座通常有爱心，乐善好施。他们很情绪化，有时会让人觉得很莫名奇妙。对朋友和家人都很忠诚，他们很重视家庭，是家庭的守\
									护者，充满了温柔的气质。有坚强的意志力、善解人意、节俭。");
		break;

	case 'e':printf("你的星座是狮子座\n");
		printf("代表王者的星座。生活中的每个角落都是狮子座们的人生秀场。他们无时无刻不彰显着自己的霸气本色。他们做事豪爽大气，讲话淡定从容，\
			   			   从不扭扭捏捏畏畏缩缩。在他们的字典里，面子优先于事理，在任何场合都绝不落下风。");
		break;

	case 'f':printf("你的星座是处女座\n");
		printf("一般将关注点都放在琐碎的事物上，但处女座人成功的秘诀往往也就在于对细节的关注，以及总是能留意到他人忽略的事物。基本上，处女座是\
			   			   非常有观察力的，但那些受处女座强烈影响的人也可能被细节捆绑，而只见树木不见林。");
		break;

	case 'g':printf("你的星座是天秤座\n");
		printf("代表秋天的星座，温柔儒雅风度翩翩是他们的标签。他们向往着快乐自在的生活，努力找寻着忠贞的友谊和美好的爱情。天秤座非常注重自身的形象\
			   			   ，落落大方，不卑不亢。在人群中，他们举手投足中都散发着天秤座特有的温柔，言行举止非常稳重。社交场上，他们淡定从容，与人为善，不喜争执\
						   			   ，总能用自己的气场去营造和谐美妙的氛围。");
		break;

	case 'h':printf("你的星座是天蝎座\n");
		printf("直觉敏锐，情感强烈是天蝎座最普遍的特点。冷静，意志非常坚定，甚至有点固执，一旦设定目标就不会轻易放手，也不会心猿意马，想东想西毫无\
			   			   目标。对于感情上的背叛绝对不能忍受，属于敢爱敢恨的类型。思虑周密，体贴是天蝎座最大的优点，可是却很少表现出来。\n");
		break;

	case 'i':printf("你的星座是射手座\n");
		printf("代表自由的星座。热情、友好、外向、直爽。他们没有人际关系中的底线，所以常常直言不讳地向人阐述自己的看法。他们的乐观的天性，可能会\
			   			   表现为喜欢随心所欲地侃侃而谈。他们天生幽默，懂得生活，时常用自己的风趣、豁达，带给身边的人欢乐。喜欢挑战，热爱冒险。喜爱去开拓新的世界\
						   			   和知识领域，拓展、延伸现有的世界。\n");
		break;

	case 'j':printf("你的星座是摩羯座\n");
		printf("独立而充满斗志。总是给人一副勤勉沉稳的样子，这是为了按部就班实现自己的目标做出来的举动。凡事有计划性，很有耐心。然而含蓄不善于表达，\
			    缺乏安全感。不过他们稳健踏实，会小心翼翼渡过艰难的处境。摩羯座对自己所爱的人非常忠诚。他们有时会有自卑情结，让人产生“渺小”的感觉，\
		        如果在家中感到被对方忽略，他们可能会被其他人的关爱所吸引。\n");
		break;

	case 'k':printf("你的星座是水瓶座\n");
		printf("有很强的自我个性，他们最大的特点是革新。他们追求独一无二的生活方式，崇尚自由。他们对人友善又注重隐私，喜欢结交每一类朋友，但是却很难\
			   			   与他们交心，要真正与他们交心需要很长的时间。他们对自己的家人会显得冷淡和疏远，不善表达自己对家人的感情。\
						   			博爱主义的水瓶座，面对爱情时缺乏执著性，从友情发展到恋情，他们常常表现得平实而没有激情，在爱情里面，水瓶座始终保持着应有的理智，不会追求缠绵的爱情。\n");
		break;

	case 'o':printf("你的星座是双鱼座\n");
		printf("双鱼座的人温柔善良，善解人意、真诚坦率、乐于助人、内心柔软、富有同情心，具有大无畏的奉献精神。\
			   			   双鱼座多情浪漫爱幻想，爱做梦，恋爱对于他们来说是生活中不可或缺的东西，而且有时候会沉溺于自己的梦\
						   			   而导致脱离现实。同时双鱼座也是很敏感脆弱的星座，他们很容易受到伤害。一旦受到伤害或是受挫，他们就会\
									   对自己失去自信心然后逃避现实。\n");
		break;
	}
}
char b(void)
{
	float num;
	char ch;
	printf("*********************************************************\n");
	printf("*                                                       *\n");
	printf("*                  欢迎您使用算星座                     *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
	printf("请输入您的出生日期：（如：三月十二日，应写成3.12 九月四号，应写成9.04....）\n");
	scanf_s("%f", &num);
	if (num >= 3.21&&num <= 4.20)
		ch = 'a';
	if (num >= 4.21&&num <= 5.21)
		ch = 'b';
	if (num >= 5.22&&num <= 6.21)
		ch = 'c';
	if (num >= 6.22&&num <= 7.22)
		ch = 'd';
	if (num >= 7.23&&num <= 8.22)
		ch = 'e';
	if (num >= 8.23&&num <= 9.23)
		ch = 'f';
	if (num >= 9.24&&num <= 10.23)
		ch = 'g';
	if (num >= 10.24&&num <= 11.22)
		ch = 'h';
	if (num >= 11.23&&num <= 12.21)
		ch = 'i';
	if (num >= 12.22 || num <= 1.20)
		ch = 'j';
	if (num >= 1.21&&num <= 2.19)
		ch = 'k';
	if (num >= 2.20&&num <= 3.20)
		ch = 'o';

	return ch;

}
void zhengxushuchu(void)
{
	printf("*********************************************************\n");
	printf("*                                                       *\n");
	printf("*                  欢迎您使用正序输出                   *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
	printf("请输入一个正整数：\n");
	
	int x;
	scanf_s("%d", &x);
	int a, b = 0, c;
	while (x > 0){
		a = x % 10;
		b = b * 10 + a;
		x /= 10;
	}
	x = b;
	while (x > 0){
		c = x % 10;
		printf("%d", c);
		if (x > 9)
			printf(" ");
		x /= 10;
	}
	printf("\n");

}