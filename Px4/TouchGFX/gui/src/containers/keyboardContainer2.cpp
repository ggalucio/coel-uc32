#include <gui/containers/keyboardContainer2.hpp>

keyboardContainer2::keyboardContainer2()
{
	restore();
}

void keyboardContainer2::initialize()
{
    keyboardContainer2Base::initialize();
}

void keyboardContainer2::restore()
{
	uppercaseKeys = false;
	numcaseKeys = false;
	shiftPressed();
}

void keyboardContainer2::InvalidateAll(){
	qTxt.invalidate();
	wTxt.invalidate();
	eTxt.invalidate();
	rTxt.invalidate();
	tTxt.invalidate();
	yTxt.invalidate();
	uTxt.invalidate();
	iTxt.invalidate();
	oTxt.invalidate();
	pTxt.invalidate();
	aTxt.invalidate();
	sTxt.invalidate();
	dTxt.invalidate();
	fTxt.invalidate();
	gTxt.invalidate();
	hTxt.invalidate();
	jTxt.invalidate();
	kTxt.invalidate();
	lTxt.invalidate();
	zTxt.invalidate();
	xTxt.invalidate();
	cTxt.invalidate();
	vTxt.invalidate();
	bTxt.invalidate();
	nTxt.invalidate();
	mTxt.invalidate();

	slashTxt.invalidate();
	dotsTxt.invalidate();
	dotcommaTxt.invalidate();
}

void keyboardContainer2::shiftPressed()
{
	if(numcaseKeys)
		return;

	uppercaseKeys =!uppercaseKeys;

	if(uppercaseKeys){
	    qTxt.setLabelText(touchgfx::TypedText(T_RESOURCEQUPID));
	    wTxt.setLabelText(touchgfx::TypedText(T_RESOURCEWUPID));
	    eTxt.setLabelText(touchgfx::TypedText(T_RESOURCEEUPID));
	    rTxt.setLabelText(touchgfx::TypedText(T_RESOURCERUPID));
	    tTxt.setLabelText(touchgfx::TypedText(T_RESOURCETUPID));
		yTxt.setLabelText(touchgfx::TypedText(T_RESOURCEYUPID));
		uTxt.setLabelText(touchgfx::TypedText(T_RESOURCEUUPID));
		iTxt.setLabelText(touchgfx::TypedText(T_RESOURCEIUPID));
		oTxt.setLabelText(touchgfx::TypedText(T_RESOURCEOUPID));
		pTxt.setLabelText(touchgfx::TypedText(T_RESOURCEPUPID));
		aTxt.setLabelText(touchgfx::TypedText(T_RESOURCEAUPID));
		sTxt.setLabelText(touchgfx::TypedText(T_RESOURCESUPID));
		dTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDUPID));
		fTxt.setLabelText(touchgfx::TypedText(T_RESOURCEFUPID));
		gTxt.setLabelText(touchgfx::TypedText(T_RESOURCEGUPID));
		hTxt.setLabelText(touchgfx::TypedText(T_RESOURCEHUPID));
		jTxt.setLabelText(touchgfx::TypedText(T_RESOURCEJUPID));
		kTxt.setLabelText(touchgfx::TypedText(T_RESOURCEKUPID));
		lTxt.setLabelText(touchgfx::TypedText(T_RESOURCELUPID));
		zTxt.setLabelText(touchgfx::TypedText(T_RESOURCEZUPID));
		xTxt.setLabelText(touchgfx::TypedText(T_RESOURCEXUPID));
		cTxt.setLabelText(touchgfx::TypedText(T_RESOURCECUPID));
		vTxt.setLabelText(touchgfx::TypedText(T_RESOURCEVUPID));
		bTxt.setLabelText(touchgfx::TypedText(T_RESOURCEBUPID));
		nTxt.setLabelText(touchgfx::TypedText(T_RESOURCENUPID));
		mTxt.setLabelText(touchgfx::TypedText(T_RESOURCEMUPID));

		slashTxt.setLabelText(touchgfx::TypedText(T_RESOURCESLASHID));
		dotsTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDOTSID));
		dotcommaTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDCID));
	}
	else{
	    qTxt.setLabelText(touchgfx::TypedText(T_RESOURCEQDNID));
	    wTxt.setLabelText(touchgfx::TypedText(T_RESOURCEWDNID));
	    eTxt.setLabelText(touchgfx::TypedText(T_RESOURCEEDNID));
		rTxt.setLabelText(touchgfx::TypedText(T_RESOURCERDNID));
		tTxt.setLabelText(touchgfx::TypedText(T_RESOURCETDNID));
		yTxt.setLabelText(touchgfx::TypedText(T_RESOURCEYDNID));
		uTxt.setLabelText(touchgfx::TypedText(T_RESOURCEUDNID));
		iTxt.setLabelText(touchgfx::TypedText(T_RESOURCEIDNID));
		oTxt.setLabelText(touchgfx::TypedText(T_RESOURCEODNID));
		pTxt.setLabelText(touchgfx::TypedText(T_RESOURCEPDNID));
		aTxt.setLabelText(touchgfx::TypedText(T_RESOURCEADNID));
		sTxt.setLabelText(touchgfx::TypedText(T_RESOURCESDNID));
		dTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDDNID));
		fTxt.setLabelText(touchgfx::TypedText(T_RESOURCEFDNID));
		gTxt.setLabelText(touchgfx::TypedText(T_RESOURCEGDNID));
		hTxt.setLabelText(touchgfx::TypedText(T_RESOURCEHDNID));
		jTxt.setLabelText(touchgfx::TypedText(T_RESOURCEJDNID));
		kTxt.setLabelText(touchgfx::TypedText(T_RESOURCEKDNID));
		lTxt.setLabelText(touchgfx::TypedText(T_RESOURCELDNID));
		zTxt.setLabelText(touchgfx::TypedText(T_RESOURCEZDNID));
		xTxt.setLabelText(touchgfx::TypedText(T_RESOURCEXDNID));
		cTxt.setLabelText(touchgfx::TypedText(T_RESOURCECDNID));
		vTxt.setLabelText(touchgfx::TypedText(T_RESOURCEVDNID));
		bTxt.setLabelText(touchgfx::TypedText(T_RESOURCEBDNID));
		nTxt.setLabelText(touchgfx::TypedText(T_RESOURCENDNID));
		mTxt.setLabelText(touchgfx::TypedText(T_RESOURCEMDNID));

		slashTxt.setLabelText(touchgfx::TypedText(T_RESOURCEMINUSID));
		dotsTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDOTID));
		dotcommaTxt.setLabelText(touchgfx::TypedText(T_RESOURCECOMMAID));
	}

	InvalidateAll();
}

void keyboardContainer2::numPressed(){
	numcaseKeys = !numcaseKeys;

	if(!numcaseKeys){
		uppercaseKeys =!uppercaseKeys;
		shiftPressed();
	}
	else{
		qTxt.setLabelText(touchgfx::TypedText(T_RESOURCE1ID));
		wTxt.setLabelText(touchgfx::TypedText(T_RESOURCE2ID));
		eTxt.setLabelText(touchgfx::TypedText(T_RESOURCE3ID));
		rTxt.setLabelText(touchgfx::TypedText(T_RESOURCE4ID));
		tTxt.setLabelText(touchgfx::TypedText(T_RESOURCE5ID));
		yTxt.setLabelText(touchgfx::TypedText(T_RESOURCE6ID));
		uTxt.setLabelText(touchgfx::TypedText(T_RESOURCE7ID));
		iTxt.setLabelText(touchgfx::TypedText(T_RESOURCE8ID));
		oTxt.setLabelText(touchgfx::TypedText(T_RESOURCE9ID));
		pTxt.setLabelText(touchgfx::TypedText(T_RESOURCE0ID));
		aTxt.setLabelText(touchgfx::TypedText(T_RESOURCECANCID));
		sTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDOLID));
		dTxt.setLabelText(touchgfx::TypedText(T_RESOURCEPERCID));
		fTxt.setLabelText(touchgfx::TypedText(T_RESOURCEECOMID));
		gTxt.setLabelText(touchgfx::TypedText(T_RESOURCESTARID));
		hTxt.setLabelText(touchgfx::TypedText(T_RESOURCEUNDID));
		jTxt.setLabelText(touchgfx::TypedText(T_RESOURCEPLUSID));
		kTxt.setLabelText(touchgfx::TypedText(T_RESOURCEBLID));
		lTxt.setLabelText(touchgfx::TypedText(T_RESOURCEBRID));
		zTxt.setLabelText(touchgfx::TypedText(T_RESOURCEAPID));
		xTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDOTSID));
		cTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDCID));
		vTxt.setLabelText(touchgfx::TypedText(T_RESOURCESLASHID));
		bTxt.setLabelText(touchgfx::TypedText(T_RESOURCEANSID));
		nTxt.setLabelText(touchgfx::TypedText(T_RESOURCECOMMAID));
		mTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDOTID));

		slashTxt.setLabelText(touchgfx::TypedText(T_RESOURCEATID));
		dotsTxt.setLabelText(touchgfx::TypedText(T_RESOURCEESCLID));
		dotcommaTxt.setLabelText(touchgfx::TypedText(T_RESOURCEDAPID));
		InvalidateAll();
	}
}
