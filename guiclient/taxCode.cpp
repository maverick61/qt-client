/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2009 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#include "taxCode.h"
#include <QDoubleValidator>
#include <QVariant>
#include <QMessageBox>

/*
 *  Constructs a taxCode as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
taxCode::taxCode(QWidget* parent, const char* name, bool modal, Qt::WFlags fl)
    : XDialog(parent, name, modal, fl)
{
  setupUi(this);

  /* Comment until new code
  // signals and slots connections
  connect(_save, SIGNAL(clicked()), this, SLOT(sSave()));
  connect(_code, SIGNAL(lostFocus()), this, SLOT(sCheck()));
  
  _taxRateA->setValidator(omfgThis->percentVal());
  _taxRateB->setValidator(omfgThis->percentVal());
  _taxRateC->setValidator(omfgThis->percentVal());
  */
}

/*
 *  Destroys the object and frees any allocated resources
 */
taxCode::~taxCode()
{
  // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void taxCode::languageChange()
{
  retranslateUi(this);
}

enum SetResponse taxCode::set(const ParameterList &pParams)
{
  QVariant param;
  bool     valid;

  /* comment until new code
  param = pParams.value("tax_id", &valid);
  if (valid)
  {
    _taxid = param.toInt();
    populate();
  }

  param = pParams.value("mode", &valid);
  if (valid)
  {
    if (param.toString() == "new")
    {
      _mode = cNew;
      _code->setFocus();
    }
    else if (param.toString() == "edit")
    {
      _mode = cEdit;
      _description->setFocus();
    }
    else if (param.toString() == "view")
    {
      _mode = cView;
      _code->setEnabled(FALSE);
      _description->setEnabled(FALSE);
      _taxRateA->setEnabled(FALSE);
      _taxRateB->setEnabled(FALSE);
      _taxRateC->setEnabled(FALSE);
      _cumulative->setEnabled(FALSE);
      _accountA->setReadOnly(TRUE);
      _accountB->setReadOnly(TRUE);
      _accountC->setReadOnly(TRUE);
      _close->setText(tr("&Close"));
      _save->hide();
      _close->setFocus();
    }
  }
  */ 
  return NoError;
}

void taxCode::sSave()
{
  /* Comment until new code
  if(_code->text().trimmed().isEmpty())
  {
    QMessageBox::warning( this, tr("No Tax Name Code"),
                          tr("You must specify a name code for this Tax.") );
    _code->setFocus();
    return;
  }

  double ratea = (_taxRateA->toDouble() / 100.0);
  double rateb = (_taxRateB->toDouble() / 100.0);
  double ratec = (_taxRateC->toDouble() / 100.0);
  int accounta = _accountA->id();
  int accountb = _accountB->id();
  int accountc = _accountC->id();

  if(ratea != 0.0)
  {
    if (!_accountA->isValid())
    {
      QMessageBox::warning( this, tr("Select G/L Accout"),
                            tr("You must select a G/L Account for this Tax.") );
      _accountA->setFocus();
      return;
    }
  }
  else
    accounta = -1;

  if(rateb != 0.0)
  {
    if (!_accountB->isValid())
    {
      QMessageBox::warning( this, tr("Select G/L Account"),
                            tr("You must select a G/L Account for this Tax.") );
      _accountB->setFocus();
      return;
    }
  }
  else
    accountb = -1;

  if(ratec != 0.0)
  {
    if (!_accountC->isValid())
    {
      QMessageBox::warning( this, tr("Select G/L Account"),
                            tr("You must select a G/L Account for this Tax.") );
      _accountC->setFocus();
      return;
    }
  }
  else
    accountc = -1;

  if (_mode == cNew)
  {
    q.exec("SELECT NEXTVAL('tax_tax_id_seq') AS _tax_id;");
    if (q.first())
      _taxid = q.value("_tax_id").toInt();
    else
    {
      systemError(this, tr("A System Error occurred at %1::%2.")
                        .arg(__FILE__)
                        .arg(__LINE__) );
      return;
    }

    q.prepare( "INSERT INTO tax "
               "( tax_id, tax_code, tax_descrip, tax_ratea,"
               "  tax_sales_accnt_id, tax_cumulative,"
               "  tax_rateb, tax_salesb_accnt_id,"
               "  tax_ratec, tax_salesc_accnt_id ) "
               "VALUES "
               "( :tax_id, :tax_code, :tax_descrip, :tax_ratea,"
               "  :tax_sales_accnt_id, :tax_cumulative,"
               "  :tax_rateb, :tax_salesb_accnt_id,"
               "  :tax_ratec, :tax_Salesc_accnt_id );" );
  }
  else
    q.prepare( "UPDATE tax "
               "SET tax_code=:tax_code, tax_descrip=:tax_descrip,"
               "    tax_ratea=:tax_ratea,"
               "    tax_sales_accnt_id=:tax_sales_accnt_id,"
               "    tax_rateb=:tax_rateb,"
               "    tax_salesb_accnt_id=:tax_salesb_accnt_id,"
               "    tax_ratec=:tax_ratec,"
               "    tax_salesc_accnt_id=:tax_salesc_accnt_id,"
               "    tax_cumulative=:tax_cumulative "
               "WHERE (tax_id=:tax_id);" );

  q.bindValue(":tax_id", _taxid);
  q.bindValue(":tax_code", _code->text().trimmed());
  q.bindValue(":tax_descrip", _description->text());
  q.bindValue(":tax_ratea", ratea);
  q.bindValue(":tax_rateb", rateb);
  q.bindValue(":tax_ratec", ratec);
  q.bindValue(":tax_sales_accnt_id", accounta);
  q.bindValue(":tax_salesb_accnt_id", accountb);
  q.bindValue(":tax_salesc_accnt_id", accountc);
  q.bindValue(":tax_cumulative", QVariant(_cumulative->isChecked()));
  q.exec();
  */
  done (_taxid);
}

void taxCode::sCheck()
{
  _code->setText(_code->text().trimmed());
  if ((_mode == cNew) && (_code->text().length()))
  {
    q.prepare( "SELECT tax_id "
               "FROM tax "
               "WHERE (UPPER(tax_code)=UPPER(:tax_code));" );
    q.bindValue(":tax_code", _code->text());
    q.exec();
    if (q.first())
    {
      _taxid = q.value("tax_id").toInt();
      _mode = cEdit;
      populate();

      _code->setEnabled(FALSE);
    }
  }
}

void taxCode::populate()
{
  /* Comment until new code
  q.prepare( "SELECT tax_code, tax_descrip,"
             "       tax_ratea * 100 AS ratea,"
             "       tax_sales_accnt_id,"
             "       tax_rateb * 100 AS rateb,"
             "       tax_salesb_accnt_id,"
             "       tax_ratec * 100 AS ratec,"
             "       tax_salesc_accnt_id,"
             "       tax_cumulative "
             "FROM tax "
             "WHERE (tax_id=:tax_id);" );
  q.bindValue(":tax_id", _taxid);
  q.exec();
  if (q.first())
  {
    _code->setText(q.value("tax_code").toString());
    _description->setText(q.value("tax_descrip").toString());
    _taxRateA->setText(q.value("ratea").toDouble());
    _accountA->setId(q.value("tax_sales_accnt_id").toInt());
    _taxRateB->setText(q.value("rateb").toDouble());
    _accountB->setId(q.value("tax_salesb_accnt_id").toInt());
    _taxRateC->setText(q.value("ratec").toDouble());
    _accountC->setId(q.value("tax_salesc_accnt_id").toInt());
    _cumulative->setChecked(q.value("tax_cumulative").toBool());
  }
  */
}

